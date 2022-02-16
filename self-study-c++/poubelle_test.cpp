#include <iostream>
#include "num.hpp"  

int main() {
    int a=2;
    int &b=a; //on copie l'adresse mémoire

    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<&b<<std::endl;
    std::cout<<&a<<std::endl;
    a=9;
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    b=10;
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
}