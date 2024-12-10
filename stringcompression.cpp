// leetcode 443 string compression 
#include<iostream>
#include<vector>
using namespace std;

int compress(vector<char>& chars) {
        int n = chars.size();
        int idx=0;
        for(int i=0;i<n;i++){
            char ch = chars[i];
            int count =0;

            while(i<n && chars[i] == ch){
                count++;i++;
            }

            if(count == 1) { chars[idx++] = ch;}
            else {
                    chars[idx++] = ch;
                    string str = to_string(count);
                    for(auto dig : str){
                        chars[idx++] = dig; 
                    }
                    
            }
            i--;
        }
        chars.resize(idx);
        return  chars.size();}
    

int main(){
    vector<char> chars = {'a','a','b','b','c','c','c'};
    cout<<compress(chars);
    for(auto i: chars){
        cout<<i;
    }
    return 0;
}
