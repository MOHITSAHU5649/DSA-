//leecode 15 3sum
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// 1.  brute force gives tle 
vector<vector<int>> threesum(vector<int> &nums){
        int n = nums.size();
        set<vector<int>> s;
        vector<vector<int>> ans;
        
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(int k =j+1;k<n;k++){
                        if(nums[i] +nums[j] +nums[k] == 0){
                            vector<int> trip = {nums[i], nums[j], nums[k]};
                            sort(trip.begin(),trip.end());

                            if(s.find(trip) == s.end()){
                                s.insert(trip);
                                ans.push_back(trip);
                            }
                        }
                }
            }
        }
        return ans;
}

// 2. in this take tar as -a then using formila take b and c 
vector<vector<int>> threesum2(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        
        for(int i =0;i<n;i++){
            int tar = -nums[i];
            set<int> ne;

            for(int j =i+1;j<n;j++){
                int third = tar -nums[j];
                if(ne.find(third) != ne.end()){
                    vector<int> trip = {nums[i],nums[j],third};
                    sort(trip.begin(),trip.end());
                    s.insert(trip);
                }
                ne.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }

//3. two pointer approach
vector<vector<int>> three(vector<int> &nums){
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());

    for(int i =0;i<n;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        int j = i+1,k = n-1;

        while(j<k){
            int sum = nums[i] +nums[j] + nums[k];
            if(sum <0){
                j++;
            }else if(sum > 0){
                k--;
            }else{
                ans.push_back({nums[i],nums[j],nums[k]});
                j++,k--;
                if(j<k && nums[j] == nums[j-1]) j++;
            }


        }
    }
    return ans;
} 


int main(){ 
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> answer = three(nums);
    for(int i =0;i<answer.size();i++){
        for(int j = 0; j<answer[i].size();j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}