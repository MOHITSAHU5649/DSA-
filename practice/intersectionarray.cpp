#include<iostream>
#include<vector>
using namespace std;

int main(){
in i =0;
int j =0;
vector<int> ans;

while(i <n && j <m){
    if(a[i] < b[j]){
        i++;
    }

    else if(a[i] > b[j]){
        j++;
    }

    else{
        ans.push_back(a[i]);
        i++;
        j++;
    }
}

cout<<ans;
    return 0;
}