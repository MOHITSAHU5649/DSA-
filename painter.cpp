#include<iostream>
#include<vector>
#include <climits>
using namespace std;

bool ispossible(vector<int> &arr,int n, int m, int mid){
    int painters = 1, time =0;

    for(int i =0;i<n;i++){
        if(time + arr[i] <= mid){
            time += arr[i];
        }else{
            painters++;
            time = arr[i];

        }
    }
    return painters <= m;
}



int check(vector<int> &arr, int n , int m){
    int sum =0, maxval = INT_MIN;
    for(int i = 0; i<n; i++){
        sum += arr[i];
        maxval = max(maxval,arr[i]);
    }

    int start = maxval, end = sum, ans = -1;

    while(start <= end){
        int mid = start +(end -start)/2;
        if(ispossible(arr,n,m,mid)){
            end = mid-1;
            ans = mid;
        }else{
            start = mid+1;
        }
    }
    return ans;
}


int main(){
    vector<int> arr = {40,30,10,20};
    int n =4, m = 2;
    cout<<check(arr,n,m);
    return 0;
}