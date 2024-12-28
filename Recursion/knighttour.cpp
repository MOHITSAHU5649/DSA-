//leetcode 2596
#include<iostream>
#include<vector>
using namespace std;

bool ktour(vector<vector<int>> &arr, int row, int col, int n, int exp){
    
    if(row<0 || col<0 || row >=n || col >= n || arr[row][col] != exp){
        return false;
    }

    if(exp == n*n-1){
        return true;
    }
    
    int ans1 = ktour(arr,row-1,col+2,n,exp+1);
    int ans2 = ktour(arr,row-2,col+1,n,exp+1);
    int ans3 = ktour(arr,row-1,col-2,n,exp+1);
    int ans4 = ktour(arr,row-2,col-1,n,exp+1);
    int ans5 = ktour(arr,row+1,col+2,n,exp+1);
    int ans6 = ktour(arr,row+2,col+1,n,exp+1);
    int ans7 = ktour(arr,row+1,col-2,n,exp+1);
    int ans8 = ktour(arr,row+2,col-1,n,exp+1);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;

}

int main(){
    vector<vector<int>> arr = {{0,3,6},{5,8,1},{2,7,4}};
    cout<<ktour(arr,0,0,arr.size(),0);
    return 0;

}