// in all the sunsequce problem we have to two possibilities take and not take 
#include <iostream>
#include <vector>           
using namespace std;

bool f(int n, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target ==0) return true;
    if(n ==0) return arr[0] == target;

    if(dp[n][target] != 0) return dp[n][target];

    bool nottake = f(n-1,target,arr,dp);
    bool take = false;
    if(arr[n] <= target){
        take = f(n-1,target-arr[n],arr,dp);
    }

    return dp[n][target] = take || nottake;
}

bool tabulation(int n, int target, vector<int> &arr){
    vector<vector<bool>> dp(n,vector<bool> (target +1, false));
    for(int i =0;i<n;i++){
        dp[i][0] = true;
    }

    for(int i =1;i<n;i++){
        for(int j = 1;j<target+1;j++){
            
        }
    }
}


int main(){
    int target = 4;
    vector<int> arr = {4,3,5,2};
    int n = arr.size();

    vector<vector<int>> dp(n,vector<int>(target+1,0));
    cout<<f(n-1,target,arr,dp);

    cout<<tabulation(n,target,arr);

    return 0;
}