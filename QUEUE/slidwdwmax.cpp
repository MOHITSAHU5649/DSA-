//leetcode 239 sliding window 
// in this we have to find the maximum element in the window of size k 

#include<iostream>
#include<deque>
#include<vector>
using namespace std;

 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for(int i=0;i<k;i++){ // first window max value in the deque
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
    
    for(int i =k;i<nums.size();i++){ // for he second to last windoow
        res.push_back(nums[dq.front()]); // first add the deqe first elemtn in the res vector then pop

        //remove ele not part of the window 
        while(dq.size() > 0 && dq.front() <= i-k){
            dq.pop_front();
        }

        while(dq.size() >0  && nums[dq.back()] <= nums[i]) // same condition as written in above 1st step
{
    dq.pop_back();
} 
    dq.push_back(i);
   }
res.push_back(nums[dq.front()]); // this is for the last window to store the front into the vector 
return res;


    }


    int main(){

        vector<int> nums = {1,3,-1,-3,5,3,6,7};
        int k = 3;
        vector<int> ans = maxSlidingWindow(nums,k);

        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }


        return 0;
    }

