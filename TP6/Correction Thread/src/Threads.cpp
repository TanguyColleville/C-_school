#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <chrono>
#include <thread>
#include <numeric>
#include <functional>
#include <algorithm>
#include <future>

#include "Chrono.hpp"
#include "ThreadPool.hpp"

using namespace std::literals;
std::mutex mtx;  

// Question préliminaire

template<typename Duration>
auto make_calcul_unaire(const char* nom, const Duration& delai) {
	return [nom, delai] (const std::string& arg){
		std::this_thread::sleep_for(delai);
		return std::string(nom) + '(' + arg + ')';
	};
}

template<typename Duration>
auto make_calcul_binaire(const char* nom, const Duration& delai) {
	return [nom, delai] (const std::string& arg1, const std::string& arg2) {
		std::this_thread::sleep_for(delai);
		return std::string(nom) + '(' + arg1 + ',' + arg2 + ')';
	};
}

// Exercice 1

void exo1() {

	auto calcul = [](const std::string& entree) -> std::string {

		// ... A compléter ...
		auto A = make_calcul_unaire("A",10ms);
		auto B = make_calcul_unaire("B",100ms);
		auto C = make_calcul_binaire("C",10ms);
		// std::future permet d'envoyer un thread en parallèle du main thread 
		std::future<std::string> resB = std::async(std::launch::async, B, entree);// en //
		std::string resA=A(entree);
		std::cout<<"Les threads sont tous terminés"<<std::endl;
		return C(resA,resB.get());
		// le main c'est le chef cuisiner qui fait de la macédoine
		// async c'est le comis qui fait la mayo dès qu'il a fini la mayo il l'a met dans le pot (future)
		// le main il fait ses bails et quand il a besoin de la mayo il regarde dans le pot (future)
		// si le chef est coincé et a besoin de la mayo il attend que le pot se remplisse
	// std::future<mayo> bol std::asyn(std::launch::async, comis , oeuf ,huile )
	// attention le bol peut prendre une exception genre comis ne sait pas faire
		// future c'est le pot de mayo

		// promesse c'est la ou on pose le pot de résultat 
		// future c'est la ou tire le résultat
	};

	Chrono chrono;
	std::cout << chrono(calcul,"e") << " calculé en " << chrono << std::endl;
}

// Exercice 2

void exo2() {

	auto calcul = [](const std::string& entree) -> std::string {

		// ... A compléter ...
		auto A = make_calcul_unaire("A",100ms);
		auto B = make_calcul_unaire("B",200ms);
		auto C1 = make_calcul_unaire("C1",200ms);
		auto C2 = make_calcul_binaire("C2",100ms);
		auto D1 = make_calcul_unaire("D1",100ms);
		auto D2 = make_calcul_binaire("D2",100ms);
		auto E = make_calcul_binaire("E",0ms);



		// std::future permet d'envoyer un thread en parallèle du main thread 
		std::future<std::string> resB = std::async(std::launch::async, B, entree);// on lance 200
		std::string resA=A(entree);// on lance 100ms 

		std::future<std::string> resC1 = std::async(std::launch::async, C1, resA); //100ms
		auto mon_res_B =resB.get();// get on peut le faire qu'une faire
		std::string resD1 = D1(mon_res_B); //100ms
		// std::future<std::string> resC2 = std::async(std::launch::async, C2, resC1.get(),resB.get()); //100ms
		std::future<std::string> resC2 = std::async(std::launch::async, C2, resC1.get(),mon_res_B); //100ms
			
		std::string resD2 = D2(resA,resD1); //100ms
		

		std::cout<<"Les threads sont tous terminés"<<std::endl;
		// return E(resC2.get(),resD2);
		return E("A","B");
	};

	Chrono chrono;
	std::cout << chrono(std::bind(calcul,"e")) << " calculé en " << chrono << std::endl;
}

// Exercice 3

void exo3() {

	auto calcul = [](const std::string& entree) -> std::string {

		// ... A compléter ...
		auto A = make_calcul_unaire("A",100ms);
		auto B = make_calcul_unaire("B",200ms);
		auto C = make_calcul_unaire("C",100ms);
		
		// l'idée c'est qu'on envoie deux commis faire de la mayo, on récupère le pot 
		// dès qu'il est remplit peu importe le commis qui l'a remplit
		std::promise<std::string> depot;
		std::future<std::string> res=depot.get_future();
		std::thread thread_A([&depot,&entree,A] () { depot.set_value(A(entree));});
		std::thread thread_B([&depot,&entree,B] () { depot.set_value(B(entree));});
		

		return C(res.get());

	};

	Chrono chrono;
	std::cout << chrono(calcul,"e") << " calculé en " << chrono << std::endl;
}

// Exercice 4

void exo4() {

	auto calcul = [](const std::string& entree) -> std::string {

		// ... A compléter ...

		return ""s;

	};

	Chrono chrono;
	std::cout << chrono(calcul,"e") << " calculé en " << chrono << std::endl;
}

// Exercice 5 (optionnel)

template<typename Iter, typename T> Iter find_multicores(Iter begin, Iter end, const T& elt) {

	// ... A compléter ...

	return end;
}

void exo5() {

	// Construction d'un vecteur contenant 0, 1, 2, ..., n
	const int n = 100000000;
	std::vector<int> vect(n);
	std::iota(vect.begin(), vect.end(), 0);

	// Recherche de val	
	int nCoeurs = std::thread::hardware_concurrency();
	int val = (n / nCoeurs) * (nCoeurs - 1);

	// Mesure du temps d'exécution de find_multicores
	Chrono chrono;
	auto it = chrono([&vect, &val]() { return find_multicores(vect.begin(), vect.end(), val); });
	std::cout << "avec " << nCoeurs << " coeurs, " << val << " trouvé à la position " << (it - vect.begin()) << " en " << chrono << std::endl;

	// et comparaison avec le find monocoeur de la STL
	it = chrono([&vect, &val]() { return find(vect.begin(), vect.end(), val); });
	std::cout << "en mono coeur, " << val << " trouvé à la position " << (it - vect.begin()) << " en " << chrono << std::endl;
}

// Problème : conception d'un réservoir de threads

template<typename Duration>
auto make_calcul(const char* nom, const Duration& delai) {
	return [nom, delai] () {
		std::this_thread::sleep_for(delai);
		std::cout << nom << "()" << std::endl;
	};
}

void prob1() {
	auto A = make_calcul("A", 100ms);
	auto B = make_calcul("B", 200ms);
	auto C = make_calcul("C", 100ms);

	// Crée le réservoir de threads
	ThreadPool pool{2};

	// Confie les calculs A, B et C au réservoir de threads
	pool(A)(B)(C);
}

void prob2() {
	auto A = make_calcul("A", 0.1ms);
	auto B = make_calcul("B", 0.1ms);
	auto C = make_calcul("C", 0.1ms);

	Chrono chrono;

	// La création du réservoir ne doit pas faire partie du code testé.
	ThreadPool pool{3};

	// Mesure du temps d'exécution de A, B et C
	chrono([&A, &B, &C, &pool] () -> void {
		pool(A)(B)(C);
		// Attend que A, B et C soient terminés
		pool.join();
	});
	std::cout << "A, B et C calculés en " << chrono << " à l'aide du réservoir de threads" << std::endl;

	// Mesure du temps d'exécution de A, B et C sans utiliser le réservoir
	chrono([&A, &B, &C] () -> void {
		std::thread a(A);
		std::thread b(B);
		std::thread c(C);
		a.join(); b.join(); c.join();
	});
	std::cout << "A, B et C calculés en " << chrono << " à l'aide de threads spécifiques" << std::endl;
}

// Le main lance la fonction de test demandée

int main( int argc, char *argv[]) {
	try {
		void(*tests[])() = { exo1, exo2, exo3, exo4, exo5, prob1, prob2 };
		constexpr int nExos = sizeof(tests)/sizeof(void(*)());

		if(argc >= 2) {
			int num = std::atoi(argv[1]);
			if(num >= 1 && num <= nExos) {
				tests[num-1]();
				return 0;
			}
		}
		throw std::invalid_argument{"syntaxe attendue : "s + argv[0] + " <numéro de l'exercice entre 1 et " + std::to_string(nExos) + ">"};
	} catch (const std::exception& e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
		return -1;
	}
}
