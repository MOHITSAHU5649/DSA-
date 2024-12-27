#include<iostream>
#include<vector>
using namespace std;

string reverse(string m){
    int end = m.length() -1;
    int start = 0;
    while(start<end){
        swap(m[start++],m[end--]);
        }
        return m;
}


int main(){
    string m = "hello";
    cout<<reverse(m);
    return 0;
}