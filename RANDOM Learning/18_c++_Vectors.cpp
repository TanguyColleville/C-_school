#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1 = {1,2,3};
    std::cout<<v1.back()<<std::endl;
    std::cout<<v1.front()<<std::endl;
    std::cout<<v1.size()<<std::endl;// number that the vector actually hold
    std::cout<<v1.capacity()<<std::endl;// number that the vector can hold
    // vector here behaves like list in python
    v1.insert(v1.begin(),4);
    v1.insert(v1.begin(),5);
    v1.insert(v1.begin()+1,18); 
    std::cout<<v1[0]<<std::endl;    
    std::cout<<"On print avec un index"<<std::endl;
    for(int i=0; i<v1.size();++i){
        std::cout<<v1[i]<<std::endl;
    }
    std::cout<<"On print avec un pointeur"<<std::endl;
    
    for(auto itr=v1.begin(); itr<v1.end();++itr){
        std::cout<<v1[*itr]<<std::endl;
    }

}