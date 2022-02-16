#include <iostream>
#include <set>
using namespace std;
/*
Un set est un ensemble non ordonné d'éléements qui doivent être unique au sein du set. 
C'est utile pour voir si un truc est répertorié ou non. 
*/
int main() {
    set<char> s1={'C','D','C','D','F'};
    s1.insert('A');
    s1.erase('F');
    for(auto itr=s1.begin(); itr!=s1.end(); itr++){
        std::cout<<*itr<<std::endl;
    }
    if(s1.find('C')==s1.end()){
        cout<<"C is not in our set"<<endl;
    } else {
        cout<<"C is in the set"<<endl;}
    string test= "i am testing some key features of set to see how it works.";
    set <char> exists;
    for (int i=0; i<test.length();i++){
        char letter = test[i];
        exists.insert(letter);
    }
    for(auto itr=exists.begin();itr != exists.end();++itr){
        cout<<*itr<<endl;
    }
}