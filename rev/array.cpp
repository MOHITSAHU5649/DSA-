#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

vector<int> brutePairSum(vector<int> &arr, int target, int n){
    vector<int> ans;
    for(int i =0;i<=n-1;i++){
        for(int j =i+1;i<n-1;i++){
            if(arr[i] + arr[j] == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

vector<int> optimalPairSum(vector<int> &arr, int target, int n){
    int i = 0;
    int j = arr.size()-1;
    vector<int> ans;
    while(i <j){
        if(arr[i] + arr[j] < target){
            i++;
        }else if(arr[i] + arr[j] > target){
            j--;
        }else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}

int kadanesALlgo(vector<int> &arr, int n){
    int currsum =0;
    int maxsum =INT_MIN;
    for(int i =0;i<n;i++){
        currsum += arr[i];
        maxsum = max(currsum,maxsum);
        if(currsum <0){
            currsum =0;
        }
    }
    return maxsum;
}

int bruteMajorityElement(vector<int> &arr, int n){
    for(int i =0;i<n;i++){
        int freq;
        for(int val : arr){
            if(arr[i] == val){
                freq++;
            }
        }    
        
        if(freq >= n/2){
            return arr[i];
        }
    }
    return -1;
}

int optimalMajorityElement (vector<int> &arr, int n){
    sort(arr.begin(),arr.end());
    int freq =1;
    int ans = arr[0];
    for(int i =1; i<n;i++){
        if(arr[i] == arr[i-1]){
            freq++;
        }else{freq =1;
            ans = arr[i];
        }
        if(freq > n/2){
            return ans;
        }
    }
    return ans;
}

int mooreVotingAlgo(vector<int> &arr, int n){
    int freq =0;
    int ans = 0;
    for(int i =0;i<n;i++){
        if(freq == 0){
            ans = arr[i];
        }
        if(ans == arr[i]){
            freq++;
        }else{
            freq--;
        }
    }
    
    // this is happen when the array is not ahving any maajprit alement 
    int count =0;
    for(int val : arr){
        if(val == ans){
            count++;
        }
    }
    if(count > n/2)  {ans;}
    else  {-1;}
    return ans;
}

int stock(vector<int> &arr, int n){
    int maxprofit =0; 
    int buy = arr[0];
    for(int i =1;i<n;i++){
        if( arr[i] > buy){
            maxprofit = max(maxprofit,arr[i] - buy);
        }
            buy = min(buy, arr[i]);
        
    }
    return maxprofit;
}

int rainWater(vector<int> &arr, int n){
    int i =0;
    int j  = n-1;
    int ans;
    
    while(i < j){
    int len = min(arr[i],arr[j]);
    int width = j-i;
    ans = max(ans, len*width);
    if(arr[i] < arr[j]){
        i++;
    }else j--;
    }
    return ans;
}

vector<int> bruteProductExceptSelf(vector<int> &arr, int n){
    vector<int> ans;
    
    for(int i =0;i<n;i++){
        int answer;
        for(int j =0;j<n;j++){
            if(i != j){
                answer *= arr[j];
            }
        }
        ans.push_back(answer);
    }
    return ans;
}

vector<int> betterProdExceptSelf(vector<int> &arr, int n ){
    vector<int> prefix;
    vector<int> suffix;
    vector<int> ans;
    
    for(int i =0;i<n;i++){
        prefix[i] = prefix[i-1] * arr[i-1];
    }
    
    for(int j = n-2;j>=0;j++){
        suffix[j] = suffix[j+1] *  suffix[j+1];
    }
    
    for(int i =0;i<n;i++){
        ans[i] = prefix[i] * suffix[i];
    }
    return ans;
}

vector<int> optimalProductExceptSelf(vector<int> &arr, int n){
    vector<int> ans(n,1);
    
    for(int i =1;i<n;i++){
        ans[i] = ans[i-1] * arr[i-1];
    }
    
    int suffix =1;
    for(int i =n-2;i>=0;i--){
        suffix *= ans[i+1];
        ans[i] *= suffix;  
    }
    return ans;
}



int main(){
    vector<int> arr = {2,7,11,15};
    int target = 9;
    int  n = arr.size();
    
   // vector<int> ans = brutePairSum(arr,target,n);
    vector<int> ans1 = optimalPairSum(arr,target,n);
    //cout<<kadanesALlgo(arr,n);
    for(auto c : ans1){cout<<c<<endl;}
    
    return 0;
}