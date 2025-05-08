//leetcode 496 
// previous nexr elemtn

#include<iostream>
#include<vector> 
#include<stack>
using namespace std;

//this is for the previous elemetn 
vector<int> pre(vector<int> &arr){
    vector<int> ans1(arr.size(),0);
    stack<int> s;

    for(int i=0;i<arr.size();i++){
        while(s.size() > 0 && s.top() >= arr[i]){
            s.pop();
        }

        if(s.empty()){
            ans1[i] = -1;
        }else{
            ans1[i] = s.top();
        }
        s.push(arr[i]);
    }
    return ans1;
}


int main(){

    vector<int> arr = {6,8,0,1,3};
    stack<int> s;
    vector<int> ans(arr.size(), 0);

    //this is the main logic igf the greater 
    //is present put in the stack and also in 
    //the ans and if the stack is empty then put -1 
    //in the aray at that postiiton which menas that there is no greater 
    //elemtns consecutively int hatt array

    for(int i =arr.size() -1;i>=0;i--){
        while(s.size() > 0 && s.top() <= arr[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i] = -1;
        }else{
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

// this is fo r the previous element 
vector<int> ans1 = pre(arr);

    // this is to print the vector
    for(int j=0;j<ans.size();j++){
        cout<<ans[j]<<" ";
    }cout<<endl;

    for(int j=0;j<ans1.size();j++){
        cout<<ans1[j]<<" ";
    }


    return 0;
}