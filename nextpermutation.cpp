#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// this is the code to find the next lexicographical number 
void nextpermu(vector<int> &nums){
    int pivot = -1, n = nums.size();

    for(int i = n-2;i>=0;i--){
        if(nums[i] < nums[i+1]){
            pivot = i;
            break;
        }
    }

    if( pivot == -1){
        reverse(nums.begin(), nums.end());
        return;
    }

    for(int i = n-1;i>pivot;i--){
        if(nums[i] > nums[pivot]){
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    reverse(nums.begin() + pivot+1, nums.end());
}



int main(){
vector<int> nums = {1,2,3};
nextpermu(nums);
int n = nums.size();
for(int p =0;p<n;p++){
    cout<<nums[p];
}
}