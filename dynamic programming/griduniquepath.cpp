#include<iostream>
#include<vector> 
using namespace std;


int helper(int i, int j, vector<vector<int>> &dp){ // memoization
    if(i == 0 && j ==0) return 1;
    if(i <0 || j<0) return 0;


    if(dp[i][j] != -1) return dp[i][j];
    int left = helper(i, j-1, dp);
    int up = helper(i-1,j, dp);

    return  dp[i][j] = left + up;
}

int tabulation(int m, int n, vector<vector<int>> &dp){
    dp[0][0] = 1;

    for(int i =0;i<m;i++){
        for(int j =0;j<n;j++){

            if(i ==0 && j ==0) { dp[i][j] = 1;
            continue;}

            int left =0, up =0;

            if(j>0) left = dp[i][j-1];
            if(i>0) up = dp[i-1][j];

            dp[i][j] = left + up;
        }
    }
    return dp[m-1][n-1];
    }


int function(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n,-1));
    return tabulation (m, n, dp);

}



int main(){
int m = 3, n =2;
cout<<function(m,n);

}