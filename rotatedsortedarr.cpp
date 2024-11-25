#include<iostream>
#include<vector>
using namespace std;

    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1; // Fix: Initialize end as nums.size() - 1
        while (st <= end) {
            int mid = st + (end - st) / 2; // Calculate mid safely

            // Check if mid is the target
            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (nums[st] <= nums[mid]) {
                if (nums[st] <= target && target <= nums[mid]) {
                    end = mid - 1; // Target is in the left half
                } else {
                    st = mid + 1; // Target is in the right half
                }
            } else {
                // Right half is sorted
                if (nums[mid] <= target && target <= nums[end]) {
                    st = mid + 1; // Target is in the right half
                } else {
                    end = mid - 1; // Target is in the left half
                }
            }
        }

        return -1;
    }

    int main(){
        cout<<"This is the search in rotated sorted array";
        int targert = 5;
        vector<int> nums = { 6,7,0,1,2,3,4,5};

        cout<<search(nums,targert);
    }