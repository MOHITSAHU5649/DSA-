#include<iostream>
#include<vector>
using namespace std;

void bubblesort(vector<int> &arr, int n){ // n^2 
    
    for(int i =0;i<n;i++){
        bool isswap = false;
        for(int j = 0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                isswap = true;
            }
        }
        if(!isswap){ 
        return;
        }
    }

}



void printarr(vector<int> &arr, int n){
    for(int i =0;i<n;i++){
        cout<<arr[i];
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();
    bubblesort(arr,n);
    printarr(arr,n);
    return 0;
}