// leetcode 78 
#include<iostream>
#include<vector>
using namespace std;

void allsub(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &all){
if(i == nums.size()){
    all.push_back({ans});
    return;
}

ans.push_back(nums[i]);
allsub(nums,ans,i+1,all);

ans.pop_back();
allsub(nums,ans,i+1,all);


return;

}


vector<vector<int>> getAllSubsets(vector<int> &nums){
    vector<vector<int>> all;
    vector<int> ans;

    allsub(nums,ans,0,all);
    return all;

}

int main(){
    vector<int> nums = {1,2,3};
     vector<vector<int>> another = getAllSubsets(nums);
     for(auto val : another){
        for(auto  k : val){
        cout<<k<<" ";}
        cout<<endl;
     }
    return 0;
    }