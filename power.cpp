// power x to n 
// 1. using loops complexity  high 
// 2. binanry 
#include<iostream>
#include<bitset>
using namespace std;

double pow(double x, int n){
    // corner cases 
    if(n==0) return 1.0;
        if(x ==0) return 0.0;
        if(x == 1) return 1.0;
        if(x == -1 && n%2 == 0) return 1.0;
        if(x == -1 && n%2 != 0) return -1.0;

    long long bin = n;
        if(n<0){
            x =1/x;
            bin = -bin;
        }
    double ans = 1;

    while (bin>0)
    {
        if (bin%2 == 1)
        {
            ans *= x;
        }
        
        x *=x;
        bin = bin/2;
    }
    return ans;
}

int main(){
double x = 2.0000;
int m = 5;
 bitset<8> n(m);
cout<<pow(x,m);
return 0;
}