//Quick sort similar to the merge sort we are dividing the array but this tiem sorting at the same time usig pivot and swapping the ele 
#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int start, int end){ // providinnt the partiion for next recurison call and also providing the sorted array
    int i = start -1, pi =arr[end];

    for(int j = start;j<end;j++){ // two pointer approach
        if(arr[j] < pi){
            i++;
            swap(arr[j],arr[i]);
        }
    }

    i++;
    swap(arr[end],arr[i]); // swapping the pivot with the end
    return i;
}

void quicksort(vector<int> &arr, int start, int end){
    if(start < end){
        int pivot = partition(arr,start,end); // find the pivot as in merge sort we find mid

        quicksort(arr,start,pivot-1);
        quicksort(arr,pivot+1,end);
    }
}

int main(){
    vector<int> arr ={12,31,35,8,32,17};
    quicksort(arr,0,arr.size()-1);

    for(auto k:arr){
        cout<<k<<" ";
    }
    return 0;
}