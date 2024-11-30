#include<iostream>
#include<vector>
using namespace std;

// this isthe dutch national flag and the optimal solution woth complexity og O(n) leetcode sort colours
// void dutchflag(vector<int> &nums, int n){
// int mid =0,low =0,high= n-1;
// while(mid<=high){
//     if(nums[mid] == 0){
//         swap(nums[mid], nums[low]);
//         mid++;
//         low++;
//     }else if(nums[mid] == 1){
//         mid++;
//     }else{
//         swap(nums[high],nums[mid]);
//         high--;
//     }
// }
// }

void dutchflag(vector<int> & nums, int n){
    int coutn0 =0, count1 =0, count2= 0;
    for(int i =0; i<n;i++){
        if(nums[i] ==0 ) coutn0++;
        else if(nums[i] == 1) count1++;
        else count2++;
    }
int index =0;
    for (int i =0;i<coutn0;i++){
        nums[index++] =0;
    }
    for (int i =0;i<count1;i++){
        nums[index++] =1;
    }
    for (int i =0;i<count2;i++){
        nums[index++] =2;
    }

}

int main(){
 vector<int> nums = {2,0,1,2,0,1};
int n = nums.size();
dutchflag(nums,n);
for(int i =0;i<n;i++){
cout<<nums[i]<<"  ";}
return 0;
}