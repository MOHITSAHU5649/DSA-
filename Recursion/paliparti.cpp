//leetcopdew 131 palindrome partition
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool ispalind(string part){
        string rev =  part;
        reverse(rev.begin(),rev.end());
        return part == rev;
    }

void helper(string s, vector<string> &partition, vector<vector<string>> &ans){
    if(s.size() == 0){
            ans.push_back(partition);
            return;
        }

        for(int i =0;i<s.size();i++){
            string part  = s.substr(0,i+1);
        if(ispalind(part)){
            partition.push_back(part);
            helper(s.substr(i+1),partition,ans);
            partition.pop_back();
        }

        }
}

vector<vector<string>> palind(string s){
    vector<string> partition;
    vector<vector<string>> ans;

    helper(s,partition,ans);
    return ans;
}

int main(){
    string s = "aab";
    vector<vector<string>> another = palind(s);
    for(auto val : another){
        for(auto k : val){
            cout<<k<<" ";
        }
        cout<<endl;
    }
    return 0;
}