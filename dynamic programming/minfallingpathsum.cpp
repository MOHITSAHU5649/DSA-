#include<bits/stdc++.h>
using namespace std;

int f(int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp){
    if(m<0 || m>=arr[0].size()) return -1e9;
    if(n ==0) return arr[0][m];

    if(dp[n][m] != -1) return dp[n][m];

    int up = arr[n][m] + f(n-1, m, arr, dp);
    int leftdiag = arr[n][m] + f(n-1, m-1, arr, dp);
    int rightdiag = arr[n][m] + f(n-1, m+1, arr, dp);

    return dp[n][m] = max(up, max(leftdiag, rightdiag));
}

void tabulation(int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp){

    for(int i =0;i<n;i++){
        dp[0][i] = arr[0][i];
    }

    for(int i =1;i<n;i++){
        for(int j =0;j<m;j++){
            int up = arr[i][j] + dp[i-1][j];
            int leftdiag = arr[i][j];
            if(j-1 >=0) leftdiag += dp[i-1][j-1];
            else leftdiag += -1e9;

            int rightdiag = arr[i][j];
            if(j+1 < m) rightdiag += dp[i-1][j+1];
            else rightdiag += -1e9;

            dp[i][j] = max(up, max(leftdiag, rightdiag));
        }
    }
   
}


int main(){
    vector<vector<int>> arr = {
        {1,2,10,4},
        {100,3,2,1},
        {1,1,20,2},
        {1,2,2,1}
    };

    int n = arr.size();
    int m = arr[0].size();
vector<vector<int>> dp(n,vector<int> (m,0));
    int maxi =0;

    // for(int j =0;j<m;j++){
    //     maxi = max(maxi, f(n-1, j, arr, dp));
    // }
tabulation(n, m, arr, dp);
    for(int i =0;i<n;i++){
        maxi = max(maxi, dp[n-1][i]);
    }

    cout<<maxi;

    return 0;


}