//product array self code 
#include<iostream>
#include<vector>
using namespace std;

// 1. BRUTE FORCE FOR THE PRODUCT OF THE ARRAY EXCEPT SELF
/* vector<int> ne(vector<int> arr){
    int n = arr.size();
    vector<int> another(n,1);
    for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(i != j){
                     another[i] *= arr[j];
                }
            }   
    }
    return another;
}  */

//2. THIS IS OPTIMAL WITH O(n) COMPLEXITY AND SPACE OF O(n)
 /* vector<int> ne(vector<int> arr){
    int n = arr.size();
    vector<int> prefix(n,1);
    vector<int> suffix(n,1);
    vector<int> ans(n,1);

    for(int i = 0; i<n;i++){
        prefix[1] = prefix[i-1] * arr[i-1];
    }

    for(int i = n-2;i>=0;i--){
        suffix[i] = suffix[i+1] * arr[i+1];
    }

    for(int i = 0;i<n;i++){
        ans[i] = prefix[i] * suffix[i];
    }

    return ans;
} */

//3. this is where space complexity is minimized by directl keep ans in asn  from O(n) yo O(1)
vector<int> ne(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n,1);

    for(int i =1;i<n;i++){
        ans[i] = ans[i-1] * arr[i-1];
    } 

    int sufix = 1;
    for(int i =n-2;i>=0;i--){
        sufix = sufix * arr[i+1];
        ans[i] = ans[i] * sufix;
    }
    return ans;

}


int main(){
    vector<int> arr = {1,2,3,4,5};
vector<int> res =  ne(arr);
    for(auto k : res){
        cout<<k<<" ";
    }
    return 0;

}