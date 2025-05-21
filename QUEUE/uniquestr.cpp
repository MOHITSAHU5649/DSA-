// this is leetcode 387 
// another leetode question implstack uisng queue and vice versa no in this code file 

#include<iostream>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;

int firstUniqChar(string s) {
        queue<int> q;
        unordered_map<char,int> m;

        for(int i =0;i<s.size();i++ ){
            if(m.find(s[i]) == m.end()){
                q.push(i);
            }

            m[s[i]]++;
        }

        while(q.size() > 0 && m[s[q.front()]] > 1 ){
            q.pop();
        }

        return q.empty() ? -1 : q.front();
    }

int main(){

     string s = "Hello";
char ans = firstUniqChar(s);
cout<<ans;
    return 0;
}