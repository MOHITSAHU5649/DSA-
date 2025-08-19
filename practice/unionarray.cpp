#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> a ={1,2,3,4,6};
    vector<int> b = {2,3,5};

    int x = a.size();
    int y = b.size();
    int i =0;
    int j =0;

    vector<int> unionarr;

    while(i<x && j<y){
        if(a[i] <= b[j]){
            if(unionarr.size() ==0 || unionarr.back() != a[i]){
                unionarr.push_back(a[i]);
            }i++;
        }
        else{
            if(unionarr.size() ==0 || unionarr.back() != b[j]){
                unionarr.push_back(b[j]);
            }
            j++;
        }
    }

    while(j<y){
         if(unionarr.size() ==0 || unionarr.back() != b[j]){
                unionarr.push_back(b[j]);
            }
            j++;
    }

    while(i<x){
        if(unionarr.size() ==0 || unionarr.back() != a[i]){
                unionarr.push_back(a[i]);
            }i++;
    }

for(auto k : unionarr){
    cout<<k<<" ";
}
    return 0;
}