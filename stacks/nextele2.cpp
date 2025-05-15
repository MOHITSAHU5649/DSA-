
//leetcode 503 , here the circular vector is givena nd just to find the next greater and the previous element
// fot this we just added the same vector so that the circulation can be done instead of using the loo fior forward and another loop for backward(circular) 
//used 2*n-1 and i%n which in rsut gioves the right index value  

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    vector<int> nums;
 int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> s;

        for(int i=2*n-1;i>=0;i--){
            while(s.size() >0 && nums[s.top()] <=nums[i%n]){
                s.pop();
            }

            ans[i%n] = s.empty() ? -1 : nums[s.top()];
            s.push(i%n);
        }

        cout<<ans;

    return 0;
}