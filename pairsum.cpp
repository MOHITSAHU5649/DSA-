// this code is pair sum code 

#include<iostream>
#include<vector>
using namespace std;

// 1. brute force 
// vector<int> pairsum(vector<int> arr, int n){
//     int  m = arr.size();
//     vector<int> ans;

//     for(int i = 0; i<m;i++ ){
//     for(int j =i;j<m;j++){
//         if(arr[i] + arr[j] == n){
//             ans.push_back(i);
//             ans.push_back(j);
//             return ans;
//         }

//     } }
//     return ans;
//      }


// int main() {
//     vector<int> arr = {2,7,11,15};
//     int target = 9;
//     vector<int> ans = pairsum(arr,target);
//     cout<<ans[0]<<ans[1];
//     return 0;
// }

// 2. OPTIMAL FOR PAIR SUM 
vector<int> pairsum(vector<int> arr, int target){
    vector<int> ans;
    int n = arr.size();

    int i = 0, j = n-1;
    while(i<j){
        int pairsum = arr[i]+arr[j];
        if(pairsum > target){
            j--;
        }
        if(pairsum < target){
            i++;
        }
        else {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int target = 7;

    vector<int> ans = pairsum(arr, target);
   
    
    cout<<ans[0] <<" " <<ans[1];
    return 0;
}