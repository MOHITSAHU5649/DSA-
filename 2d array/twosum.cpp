//leetcode 1
#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

vector<int> twosum(vector<int>&arr, int target){
    unordered_map <int,int> n ;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        int start = arr[i];
        int second = target - start;

        if(n.find(second) != n.end()){
            ans.push_back(i);
            ans.push_back(n[second]);
            
        }
        n[start] = i;
    }
    return ans;
    
}


int main(){
    vector<int> arr = {2,7,11,15};
    int target = 9;
    vector<int> indices = twosum(arr,target);
     for (int index : indices) {
        cout << arr[index] << " ";
    }
    return 0;
}