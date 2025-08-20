//leecode 15 3sum
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// 1.  brute force gives tle 
vector<vector<int>> threesum(vector<int> &nums){
        int n = nums.size();
        set<vector<int>> s; // to store differnnt tripelets 
        vector<vector<int>> ans;
        
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(int k =j+1;k<n;k++){
                        if(nums[i] +nums[j] +nums[k] == 0){
                            vector<int> trip = {nums[i], nums[j], nums[k]}; // store that triplet
                            sort(trip.begin(),trip.end()); // arange so that next same can be also catched

                            if(s.find(trip) == s.end()){ // agar nahi mila to dal do 
                                s.insert(trip); // ya pe daal rehe hai 
                                ans.push_back(trip); // yaha ans me daal rehe hai 
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
            int tar = -nums[i]; // took the first val
            set<int> ne; 

            for(int j =i+1;j<n;j++){
                int third = tar -nums[j]; // with that  number we select the other two as third and j 
                if(ne.find(third) != ne.end()){ // if thord hai to kaam hogya 
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
        if(i>0 && nums[i] == nums[i-1]) continue; // if the n and the previous of n is same that means we will get same triplet therofrer skip
        int j = i+1,k = n-1; // set j and k 

        while(j<k){
            int sum = nums[i] +nums[j] + nums[k];
            if(sum <0){
                j++;
            }else if(sum > 0){
                k--;
            }else{
                ans.push_back({nums[i],nums[j],nums[k]}); // traverse ja nd k and get the result as , increment and decrement ja dn k 
                j++,k--;
                if(j<k && nums[j] == nums[j-1]) j++; // here, wahi agar j or j- same to firse kyo dekhe bahi 
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