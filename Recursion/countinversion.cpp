// count inversion 
#include<iostream>
#include<vector>
using namespace std;

//1. brute force 
int count(vector<int> &arr){

    int count1 =0;
    for(int i =0;i<arr.size();i++){
        for(int j = i+1;j<arr.size();j++){
            if(arr[i] > arr[j]){
                count1++;
            }
        }
    }
    return count1;
}

int merge(vector<int> &arr, int start, int mid, int end){
    vector<int> temp;
    int i = start, j = mid+1;
    int invc =0;

    while(i<= mid && j<= end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
            invc += (mid -i+1); 
        }
    }
        while(i<= mid){
            temp.push_back(arr[i]);
            i++;
        }

        while (j<= end)
        {
            temp.push_back(arr[j]);
            j++;
        }

        for (int i = 0; i < temp.size(); i++)
        {
            arr[i+start] = temp[i];
        }  
    

    return invc;
}

int mergesort(vector<int> &arr, int st, int end){
    if(st<end){

        int mid  = st +(end -st)/2;

        int left = mergesort(arr,st,mid);
        int right  = mergesort(arr,mid+1,end);

        int inv = merge(arr,st,mid,end);

        return left + right + inv;
    }
    return 0;
}

int main(){

    vector<int> arr = {6,3,5,2,7};
    int ans = count(arr);
    cout<<ans<<endl;
    int count2  = mergesort(arr,0,arr.size()-1);
    cout<<count2;
    
    
    return 0;
}