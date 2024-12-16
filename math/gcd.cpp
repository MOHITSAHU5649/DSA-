#include<iostream>
using namespace std;

//1. brute force un which a loop is used 
int gcd(int a , int b){
    int gc =1;
    for(int i =1;i<min(a,b);i++){
    if(a == 0) return b;
    if(b == 0) return a;
    if(a == b) return a;

    if(a%i == 0 && b%i ==0){
        gc =  i;
    }
    }
    return gc;
}

//2. eculid algorithm 
int gcdecu(int a, int b){
    while(a>0 && b>0){
        if(a>b){
            a = a%b;
        }else{
            b =b%a;
        }

    }
    if(a == 0)  return b;
    return a;
}

//3. eculid recursion
int gcdrec(int a, int b){
    if(b==0) return a;
    return gcdrec(b, a%b);
}

// LCM

int lcm(int a, int b){
    int gcdn = gcd(a,b);
    return (a*b)/gcdn;
}
int main(){
    int a = 20, b=28;
    cout<<gcdecu(a,b);
    cout<<gcdrec(a,b);
    cout<<gcd(a,b);
    cout<<lcm(a,b);
    return 0;
}