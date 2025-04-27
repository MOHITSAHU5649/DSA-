//ovelapping sub problems, memoization tend to store some value in the map to access time whenever we needed 
//chechk that the problems is doen earlier if yes they why dto do thta again


#include<iostream>
#include<vector>
using namespace std;

int f(int n, vector<int> &dp){ // memoization
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = f(n-1,dp) + f(n-2,dp);
}

int fib(int n, vector<int> & dp){ // tabulation form base case to the answer
    dp[0] = 0;
    dp[1] =1;

    for(int i =2;i<=n;i++)
{dp[i] = dp[i-1] + dp[i-2];
}}

int fibopt(int n){ // this is space optimized 
    int prev2 =0; int prev1 = 1;

    for(int i= 2;i<=n;i++){
        int cur = prev1 +prev2;
        prev2 = prev1;
        prev1 = cur;
    }
}

int main(){
    int n = 5;
    vector<int> dp(n+1, -1);
    cout<<f(n,dp);

    return 0;
}