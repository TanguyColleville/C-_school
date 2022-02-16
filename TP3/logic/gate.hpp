#pragma once
#include <iostream>
#include <memory>
#include <iomanip>  // formatting stuff here
#include <list>
#include <map>


#define gate_NAME_WIDTH 17
#define gate_TIME_WIDTH  9


using ref_action = std::shared_ptr<std::function<void ()>>;


namespace gate {

  // Write all your code here
  inline void ____(){
    std::cout << std::left << "+-----------------+---------+-----+"<<std::endl; 
  }

  inline void ____display(double time, std::string name, bool status){
    std::cout.precision(2);
    std::cout<<std::left <<"|"<<std::setw(gate_NAME_WIDTH)<<name<<"|";
    std::cout<<std::right<<std::setw(gate_TIME_WIDTH)<<time<<"|";
    if(status){
    std::cout<<std::left<<"  on |"<<std::endl;
    }
    else {
      std::cout<<std::left<<" off |"<<std::endl;
    }
  }
  using ref_action = std::shared_ptr<std::function<void ()>>;// permet d'éviter d'écrire ça
  // tout le temps. 
  using wref_action=std::weak_ptr<std::function<void ()>>;// version weak

  inline ref_action action(std::function<void ()> function_to_copied){ // on passe en argument une
  // fonction de type void et 
    // on doit renvoyer un sharepointeur de la fonction passée en argument
      auto shared_ptr=std::make_shared<std::function<void()>>(function_to_copied);
      return shared_ptr;
  }

  inline void execute(ref_action ma_ref){
    (*ma_ref)();// () est prioritaire sur * donc si on ne met pas parenthèse
    // il fait *(ma_rref()) alors qu'on veut (*ma_ref)(); 
  }

// on veut maintenant que les actions soient des weak ref 
  using ref_wire = std::shared_ptr<std::pair<std::list<wref_action>,bool>>;


  //inline ref_wire wire(std::list<wref_action> my_actions,bool status=false){// on doit pouvoir
  //construire sans rien mettre dedans
  inline ref_wire wire(){
    return std::make_shared<std::pair<std::list<wref_action>,bool>>(std::list<wref_action>(), false);
    // std::list<wref_action>() ça créer une liste vide dont les éléments seront des wref_action
  }


  inline bool value(ref_wire wire){
    return std::get<1>(*wire);// on prend le bool status 
  }

  inline void link(ref_wire wire, ref_action gate){
    std::get<0>(*wire).push_back(gate);// ajoute à la list de ref d'actions notre ref action 
  }

  inline void set(ref_wire wire,bool status){
    //std::cout<<"état de wire"<<value(wire)<<std::endl;
    //std::cout<<"état de statue"<<status<<std::endl;
    if(value(wire)!=status){// si on le change d'état
      std::get<1>(*wire)=status;// on affecte la nouvelle valeur
      //std::cout<<"état de wire après modif"<<value(wire)<<std::endl;
      for(auto& action : std::get<0>(*wire)){
        // attention * d'un weak ça marche pas 
        auto act=action.lock();// lock ça renvoie un shared si le weak existe
        if (act){
          execute(act);// on doit passer un shared pointeur dans le execute
        }
      }
  }
  }
/*              AGENDA             */
  // on définit une ref sur l'agenda pour pas l'écrire tout le temps

  using ref_agenda = std::shared_ptr<std::tuple<double, std::multimap<double, std::tuple<ref_wire, bool>>> > ; 
  // en premier le temps de l'agenda et ensuite une liste de heure, et  tuple(wire, état)
  inline ref_agenda agenda(){
    return std::make_shared<std::tuple<double, std::multimap<double, std::tuple<ref_wire, bool>>>> (0, std::multimap<double, std::tuple<ref_wire, bool>>()); 
  }
  inline double now(ref_agenda a) {return std::get<0>(*a);
}

void notify(ref_agenda a, ref_wire w, bool status, double delay) {
  std::get<1>(*a).insert({now(a) + delay, {w, status}});// on ajoute à l'agenda 
  // une action qu'on devra faire dans maintenant + delay qui sera passer le wire w à l'état status
  }

bool next(ref_agenda agenda){
    auto& requests = std::get<1>(*agenda);// on récupé la multi map (heure, tuple(wire,état))
    if(requests.size() == 0) return false; // s'il n'y en a pas on return faux i.e. rien à faire 
    auto next_it = requests.begin();// on pointe sur le début 
    auto [time, request] = *next_it;// time c'est la date &request c'est la paire (ref wire, état) 
    requests.erase(next_it);// on la supprime des requests
    std::get<0>(*agenda) = time;// on met à jour l'heure now de notre agenda
    set(std::get<0>(request), std::get<1>(request));// on lance la commande à l'état indiqué
    return true;
  }


inline void flush(ref_agenda a) {while(next(a));} // polymorphisme de type
inline void flush(ref_agenda a, unsigned int nb_steps) {unsigned int n = 0; while((n++ < nb_steps) && next(a));}


inline auto PROBE(ref_agenda a , const std::string& text, ref_wire wire){
  auto act=action([a, text, wire](){____display(now(a), text, value(wire));});
  // on crée une action à partir du displau de now agenda le text c'est l'ancien name et l'état 
  // associé. 
  link(wire, act);// on lie le cable à l'action en l'ajoutant à la liste d'actions du wire
  return act; // on renvoie l'action
}

auto AND(ref_agenda a, ref_wire in_1, ref_wire in_2, ref_wire out) {
  auto act = action([a, in_1, in_2, out](){notify(a, out, value(in_1) && value(in_2), .5);});
  link(in_1, act);
  link(in_2, act);
  execute(act); // Sets the effect on the gate plugging on the output wire.
  return act;
}

auto OR(ref_agenda a, ref_wire in_1, ref_wire in_2, ref_wire out) {
  auto act = action([a, in_1, in_2, out](){notify(a, out, value(in_1) || value(in_2), .5);});
  link(in_1, act);
  link(in_2, act);
  execute(act); // Sets the effect on the gate plugging on the output wire.
  return act;
}

auto NOT(ref_agenda a, ref_wire in, ref_wire out) {
  auto act = action([a, in, out](){notify(a, out, !value(in), .5);});
  link(in, act);
  execute(act); // Sets the effect on the gate plugging on the output wire.
  return act;
}

auto XOR(ref_agenda a, ref_wire in_1, ref_wire in_2, ref_wire out) {
   // Internal actions will handle these wires into their
    // closures... so they will survive to the exit of this code.
    auto w1 = wire();
    auto w2 = wire();
    auto w3 = wire();
    auto w4 = wire();

    auto g1 = NOT(a, in_1, w1     );
    auto g2 = NOT(a, in_2, w2     );
    auto g3 = AND(a, in_1, w2, w3 );
    auto g4 = AND(a, in_2, w1, w4 );
    auto g5 = OR (a, w3  , w4, out);

    // Keeping gates alive in the closure is the trick
    // for integrated circuits.
    return action([g1, g2, g3, g4, g5]() {});
  }

}