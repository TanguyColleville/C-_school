#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    // Variables
    int age(10); // Notation équivalente à : int age = 10; mais plus propre
    int age2 = age;
    age2 = 20;

    cout << age << age2 << endl;

    // Première utilisation de l'esperluette : passage par référence
    int& age3 = age; // passage par référence : age3 et age pointe vers la même case mémoire. Modifier la valeur de l'un => modifier la valeur de l'autre.
    cout << age3 << endl;

    age3= 50;

    cout << age << age3 << endl;

    // Deuxième  utilisation de l'esperluette : obtenir adresse mémoire d'une variable
    cout << "L'adresse est : " << &age <<endl;


    // Pointeur *
    // def : un pointeur est une variable qui contient l'adresse d'une autre variable
    int *ptr(0); // Toujours initialiser un pointeur à la valeur 0, même si c'est un char, un string...
    ptr = &age; // on affecte à ptr l'adresse mémoire de age

    cout << ptr << endl;// Affiche l'adresse mémoire
    cout << *ptr << endl;// Affiche la valeur de la variable "pointée" par le pointeur. "Accéderà la valeur de la variable pointée", "déréférencer" un pointeur.
    delete ptr;
    ptr=0;
    
    // Allocation dynamique
    // Permet d'allouer un espace mémoire : on demande manuellement une case dans la mémoire du pc

    int *pointeur(0);
    pointeur = new int; // new demande une case mémoire à l'ordinateur et renvoie un pointeur pointant vers cette case

    // /!\ il ne faut pas changer la valeur du pointeur sinon on perd DEFINITIVEMENT le seul moyen d'accéder à la case mémoire => on ne peut plus l'utiliser ni la supprimer.
    // c'est ce qu'on appelle une fuite de mémoire

    // On peut accèder à la case mémoire pour en modifier la valeur comme ceci
    *pointeur = 2; // On modifie bien la valeur dans la case mémoire allouée manuellement, pas la valeur du pointeur

    cout << "Adresse de la case mémoire allouée : " <<pointeur << endl;
    cout << "Valeur dans la case mémoire allouée : " <<*pointeur << endl;

    // /!\ Une fois que l'on n'a plus besoin de la mémoire, il faut la libérer pour l'ordinateur
    // on utilise l'opérateur delete puis une affection de l'adresse mémoire à 0
    // TRES IMPORTANT DE TOUJOURS LE FAIRE SINON ON VA SATURER LA MEMOIRE DU PC AU FIL DES EXECUTIONS DU PROGRAMME
    delete pointeur; // Libère la mémoire
    pointeur = 0; // Permet de mettre le pointeur à l'adresse 0, pour qu'il ne pointe vers plus rien.




    return 0;
}
