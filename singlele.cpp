//THIS IS THE CODE FOR THE SINGLE ELEMENT IN THE SORTED ARRAY 
#include<iostream>
#include<vector>
using namespace std;

int singleele(vector<int> &arr){
    int n = arr.size();
    if(n ==0 ) return arr[0];
    int start =0, end = n -1;
    while(start <= end){
        int mid = start +(end -start)/2;
        if(mid == 0 && arr[0] != arr[1]) return mid;
        if(mid == n && arr[n-1] != arr[n-2])  return mid;
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return mid;

        if(mid % 2 == 0){
            if(arr[mid] == arr[mid-1]){
                end = mid-1;
            } else{
                start = mid+1;
            }
        }else{
            if(arr[mid] == arr[mid -1]){
                start = mid+1;
            }else {
                end = mid -1;
            }
        } 
    }
    return 0;

}



int main(){
    vector<int> arr = {3,3,7,7,10,11,11};
    cout<<singleele(arr);
    return 0;
}