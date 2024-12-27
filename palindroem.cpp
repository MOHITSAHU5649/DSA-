#include<iostream>
using namespace std;

// bool alpha(char c){
//             if((c>='0' && c<='9')  || (tolower(c) >= 'a' && tolower(c)<='z')){
//                 return true;
//             } 
//             return false;
//         }

bool palindrome(string m){
    int start =0, end = m.length();
    while(start<end){
    
    if(!iswalnum(m[start])){
        start++; continue;
    }
    if(!iswalnum(m[end])){
        end--; continue;
    }

    if(tolower(m[start]) != tolower(m[end])){
        return false;
    }
    start++; end--;

    }
    return true;
}


int main(){
    string s;
    s= "madam";
    cout<<palindrome(s);
    return 0;
}