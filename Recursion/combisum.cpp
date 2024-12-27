// leetcode 39
#include<iostream>
#include<vector>
#include<set>
using namespace std;

    set<vector<int>> s;
    void findall(vector<int> &arr, int index, int target, vector<int> &combi, vector<
    vector<int>> &ans){
        if(index == arr.size() || target<0){
            return;
        }

        if(target == 0){
            if(s.find(combi) == s.end()){
                ans.push_back(combi);
                s.insert(combi);
            }
            return;
        }

        combi.push_back(arr[index]);
        findall(arr,index+1,target- arr[index],combi,ans);
        findall(arr,index,target- arr[index],combi,ans);
        combi.pop_back();
        findall(arr,index+1,target,combi,ans);

    }

 vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    vector<int> combi;
    vector<vector<int>> ans;

    findall(arr,0,target,combi,ans);
    return ans;        
    }

int main(){
    vector<int> arr = {2,3,6,7};
    int target = 7;
    vector<vector<int>> another = combinationSum(arr,target);
    for(auto val : another){
        for(auto k : val){
            cout<<k<<" ";
        }
        cout<<endl;
    }
    return 0;
}