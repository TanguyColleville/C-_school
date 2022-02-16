template<class T>
#include <iostream>
using namespace std;


void swap(T& a, T& b)
    {
    std::cout<<a<<std::enl;
    T tmp(std::move(a));// équivalent a : T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
    }
int main(){
    int a(6);
    int b(2);
    swap(a,b);
}
