//leetcode 287
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// first easiest approcah 
int duplicate(vector<int> &arr){
    unordered_set<int> m;

    for(int val : arr){
        if(m.find(val) != m.end()){ // if already exist the number then it is the dulicate number 
            return val;
        }

        m.insert(val); // agar nahi hai to daal do 
    }
    return -1;
}

//2. slow fast approach
int dup(vector<int> &arr){
    int slow =arr[0], fast = arr[0]; // slow or fast ko declare karo 

    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = arr[0];// jaise he slow fast ek hote hai to slow ko wapas 0 pe le 

    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
    
}

int main(){
    vector<int> arr = {1,3,4,2,2};
    cout<<dup(arr);
    cout<<duplicate(arr);
    return 0;
}