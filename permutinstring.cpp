// leetcode 567 permutaion in string in which a string is givena dn we have to checek the permutaion of another string inthe mainn string 

#include<iostream>
#include<algorithm>
using namespace std;

bool done(int freq[], int fre[]){
    for(int i= 0;i<26;i++){
        if(freq[i] != fre[i]){
            return false;
        }
    }
    return true;
}

bool check(string s1, string s2 ){
    int freq[26] = {0};
    for(int i =0;i<s1.length();i++){
        freq[s1[i] - 'a']++;
    }

    int windowsize = s1.length();
    for(int i =0;i<s2.length();i++){
        int wind = 0, idx = i;
        int fre[26] = {0};

        while(wind < windowsize && idx < s2.length()){
            fre[s2[idx] -'a']++;
            wind++, idx++;
        }

        if(done(freq, fre)){
            return true;
        }
    }
    return false;

}
    
int main(){
    string s2 = "eidbaooo";
    string s1 = "ab";

    cout<<check(s1,s2);
    return 0;
}