#include<iostream>
using namespace std;

void insertion(int arr[], int n){
    for(int i = 1;i<n;i++){
        int curr = arr[i]; //1
        int prev = i-1; //4
        while(prev >=0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }

        arr[prev+1] = curr;
    }
}

void printarr(int arr[], int n){
    for(int i =0;i<n;i++){
        cout<<arr[i];
    }
}

int main(){
     int n =5;
    int arr[n] ={4,1,5,2,3};
    insertion(arr,n);
    printarr(arr,n);
    return 0;
}