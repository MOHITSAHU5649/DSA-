#include<iostream>
#include<vector>
#include<climits>
#include <algorithm>
using namespace std;

bool isposs(vector<int>&arr,int n, int c, int mid){
    int cows =1, lastposs = arr[0];
    for(int i = 1;i<n;i++){
        if(arr[i] - lastposs >= mid){
            cows++;
            lastposs = arr[i];
        }
        
    
    if(cows == c) {return true;}
}
return false;
}



int cows(vector<int> &arr,int n, int c){
    sort(arr.begin(),arr.end());
    int start = 0, end = arr[n-1] -arr[0], ans = -1;
    while (start<= end)
    {
        int mid = start + (end - start)/2;
        if(isposs(arr,n,c,mid)){
            ans = mid;
            start = mid +1;
           
        }else{
             end = mid-1;
        }
    }return ans;
}




int main(){
    vector<int> arr = {1,2,8,4,9};
    int n = 5, c =3;
    cout<<cows(arr,n,c);
    return 0;

}