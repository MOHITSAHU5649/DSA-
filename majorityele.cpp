#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 1. BRUTE FORCE TO FIND THE MAJORITY ELEMNT 
/* int major(vector<int> arr){
    int m = arr.size();
    for(int i :arr){
        int freq = 0;
        for(int j : arr){
            if(arr[i] == arr[j]){
                    freq++;
            }
            if(freq > m/2){
                return i;
            }
        }
    }
    return -1;
} */

//2. THIS IS OPTIMAL TO FIND THE MAJORITY ELEMNT
/* int major(vector<int> arr){
    int n = arr.size();
    
    sort(arr.begin(), arr.end());
    int freq = 1, ans = arr[0];
    for(int i = 1;i<n;i++){
        if(arr[i] == arr[i-1]){
                freq++;
        }
        else{
            ans = arr[i];
            freq = 1;
        }
    }
    if(freq > n/2){
        return ans;
    }
return ans;
} */

//3. THIS IS MOORE'S VOTING ALGORITHM
int major (vector<int> arr){
    int freq =0, ans = 0;
    for(int i= 0;i<arr.size();i++){
        if(freq ==0){
            ans = arr[i];
        }
        if(ans == arr[i]){
            freq++;
        }
        else{
            freq--;
        }

    }
    int count =0;
    for(int k : arr){
        if(k == ans){
            count++;
        }
    }

    if(count>arr.size()/2)  ans;
        else  -1;


    return ans;
}



int main(){
    vector<int> arr = { 2,1,1,2,2,2};
    cout<<major(arr); // THIS IS 1.

    return 0;

}