#include<iostream>

using namespace std;

void selection(int arr[], int n){
    for(int i =0;i<n;i++){
    int smallest = i;
    for(int j =i+1;j<n;j++){
        if(arr[j]  < arr[smallest]){
            smallest =j;
        }
    }
    swap(arr[i],arr[smallest]);
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
    selection(arr,n);
    printarr(arr,n);
    return 0;
}