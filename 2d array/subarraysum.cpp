// leectode 560 
#include<iostream>
#include<vector>
#include<unordered_map>
#include "subarraysum.h"
using namespace std;


//1 brute force n^2 
int sumarr(vector<int> nums, int target){
    int n = nums.size();
    int sount  =0;

    for(int i =0;i<n;i++){
        int sum =0;
        for(int  j =i;j<n;j++){
            sum += nums[j];
            if(sum == target){
                sount++;
            }
        }
    }
    return sount;
}

//2. optimized using unordered map 
int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int> pre (n,0);

        pre[0] = nums[0];

        for(int i =1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }

        unordered_map <int,int> m;
        for(int j = 0;j<n;j++){
            if(pre[j] == k) count++;

// this lines is the core of unordered map
            int val = pre[j] - k;
            if(m.find(val) != m.end()){
                count += m[val];
            }
            if(m.find(pre[j]) == m.end()){
                m[pre[j]] = 0;
            }
                m[pre[j]]++;


        }
        return count;
    }

int main(){
    vector<int> nums ={1,1,1};
    int tar =2;
    cout<<subarraySum(nums,tar);
    cout<<sumarr(nums,tar);
    return 0;
}