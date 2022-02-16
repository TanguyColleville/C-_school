#include <iostream>
using namespace std;
/*

*/
int add(int x, int y){
    return x+y;// on stop au premier return rencontré donc le deuxième ne sera pas considéré
    return x*y;
}
int get_number(){

    return 6;// ça renvoie juste 6
}

void print_n_times(int n){
    for(int i=0;i<n;i++){
        cout<<i<<endl;
    }
}


int main() {
    int results=get_number(); //il faut mettre les parenthèses même vide pour appeler la fonction sans argument 
    print_n_times(7);
}