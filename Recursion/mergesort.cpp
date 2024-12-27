// merge sort using recurisona nd backtarcking 
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int start, int end, int mid){ // fun to merge the ele for sorting backtracking
    vector<int> temp;
    int i =start, j = mid+1;

    while(i<= mid && j <= end){ // compare lel to sort
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
        
    }

    while (i<= mid) // keepinnt rest ele in the temp
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j<= end) // keepint rest le ein the temp
    {
        temp.push_back(arr[j]);
        j++;
    }

    for(int i=0;i<temp.size();i++){ // puttinf temp to original array
        arr[i+start] = temp[i];
    }
    
    
}

void mergesort(vector<int> &arr, int start, int end){ // recursion to find the mid and divide the array 
    if(start<end){
        int mid = start +(end -start)/2;

        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);

        merge(arr,start,end,mid); // backtacking to sort and add the array 
    }
    
}


int main(){
    vector<int> arr = {12,31,35,8,32,17};
    mergesort(arr,0,arr.size() -1);

    for(auto k : arr){
        cout<<k<<" ";
    }
    return 0;
}