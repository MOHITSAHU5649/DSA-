// leetcode 78 
#include<iostream>
#include<algorithm>
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


// a variation of ths ame is to not take the duplicaes 
void allsub2(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &all){
if(i == nums.size()){
    all.push_back({ans});
    return;
}

ans.push_back(nums[i]);
allsub2(nums,ans,i+1,all);

ans.pop_back();
int idx =i+1;
while(idx < nums.size() && nums[idx] == nums[idx-1]){
    idx++;
}
allsub2(nums,ans,idx,all);


return;

}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end()); 
        vector<vector<int>> all;
    vector<int> ans;

    allsub2(nums,ans,0,all);
    return all;
       
    }
int main(){
    vector<int> nums = {1,2,3};
    vector<int> nums1 = {1,2,2};
     vector<vector<int>> another = getAllSubsets(nums);
     vector<vector<int>> another1 = subsetsWithDup(nums1);

     for(auto val : another){
        for(auto  k : val){
        cout<<k<<" ";}
        cout<<endl;
     }

     for(auto val : another1){
        for(auto  k : val){
        cout<<k<<" ";}
        cout<<endl;
     }
    return 0;
    }