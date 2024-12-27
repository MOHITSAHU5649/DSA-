// leetcode 46

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void getper (vector<int> &nums, int i , vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back({nums});
            return;
        }
        for(int j = i;j<nums.size();j++){
        swap(nums[i], nums[j]);

        getper(nums, i+1,ans);
       swap(nums[j],nums[i]);

        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans ;
        getper(nums, 0,ans);
        return ans;
    }


int main(){
    vector<int> nums = {1,2,3};
    
     vector<vector<int>> another = permute(nums);
    
     for(auto val : another){
        for(auto  k : val){
        cout<<k<<" ";}
        cout<<endl;
     }

     
    return 0;
    }