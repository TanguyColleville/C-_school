#include <iostream>
using namespace std;

int factoriel(int x){// entier positif 
    if x<0;
    throw x; // on lance x 
    else {
        int fact=1 
        for(int i=2;i<x;i++){
            fact*=i;
        }
    return fact;}
}

int main(){
    int A;
    cin>>A;
    try{
        int r(factoriel(A));
        cout<<A<<"! = "<<r<<endl;
    }
    catch (int e){// on choppe l'erreur si y'en a une elle sera de type int puisque c'est x 
    cout<<"pas possible de calculer facto d'un nombre neg "<<e<<"!"<<endl;
    }


    return 0;

}