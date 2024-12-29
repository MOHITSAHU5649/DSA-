//THIS IS THE CODE FOR BINANRY SEARCH 
#include<iostream>
#include<vector>
using namespace std;

int binsearch(vector<int> nums, int target){
     int start = 0, end = nums.size() - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] < target){
                start = mid+1;
            }
            else if(nums[mid] > target){
                end =mid -1;
            }
            else{
                return mid;
            }

        }
        return -1;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int target = 6;
    cout<<binsearch(arr,target);
    return 0;
}