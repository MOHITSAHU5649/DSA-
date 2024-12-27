#include<iostream>
#include<vector>
using namespace std;
//here brute force gives tle
bool isprime(int N){
for(int j =2;j<=N;j++){
        bool prime = true;


    for(int i =2;i*i<=j;i++){
        if(j%i == 0){
           prime = false;
           break;
            // return false;
        }
        
    }
    prime = true;
    return prime;}
}

// sieve of eratosheses eliminates all the multiples of prime numbers 
int  countprime(int n){
vector<bool> isprime(n+1,true);
        int count = 0;

        for(int i =2;i<n;i++){
            if(isprime[i]){
                count++;
            }
            for(int j =i*2;j<n;j = j+i){
                isprime[j] = false;
            }
            
        }
        return count;
    }

int main(){
    int num = 50;
    cout<<countprime(num);
    // cout<<isprime(num);
    return 0;
}