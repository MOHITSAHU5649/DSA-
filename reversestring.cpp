//leetcode 151  reverse a string eliminating the space from it 
#include<iostream>
#include<algorithm>
using namespace std;

string rev(string s){
    int n = s.length();
    string ans= "";
    reverse(s.begin(),s.end());

    for (int i = 0; i <n; i++)
    {
        string word= "";
        while (i<n && s[i] != ' ')
        {
            word += s[i];
            i++;
        }

        reverse(word.begin(),word.end());
        ans += " "+ word;
        
    }
    return ans.substr(1);
    
}

int main(){
    string str = "My name is MOHIT SAHU";
    cout<<rev(str);
    return 0;
}