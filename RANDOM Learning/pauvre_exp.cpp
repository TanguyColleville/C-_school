#include <iostream>
using namespace std;

int factoriel(int x){// entier positif 
    int fact=1 
    for(int i=2;i<x;i++){
        fact*=i;
    }
    return fact;
}

int main(){
    int A;
    cin>>A;

    //méthode du pauvre pour gérer l'erreur
    if (A<0){cout<<"impossible de calculer son factoriel"<<endl;}
    else {cout<<"factoriel de A = "<<factoriel(A)<<endl;}


    return 0;

}