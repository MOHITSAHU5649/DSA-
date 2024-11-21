#include<iostream>
using namespace std;

//1. PASS BY REFERENCE BY POINTER 
/*int change(int * ptr){
        *ptr = 20;
    return *ptr;}

int main(){
    int a = 10;
    change(&a);
    cout<<a;
    return 0;
}*/

//2. PASS BY REFERENCE ALIS
int change( int &a){
    a = 20;
    return a;
}

int main(){
    int a = 10;
    change(a);
    cout<<a;
    return 0;
}