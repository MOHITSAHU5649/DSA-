//pani bhara hai two bars ke beech me pata karna hai knsi two barr me pani zada 
#include<iostream>
#include<vector>
using namespace std;

//1. BRUTE FORCE TO FIND MAX AREA FOR WATER 
/* int max(vector<int> bars){
    int n = bars.size();
    int area =0, w,h;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            w = j - i;
            h = min(bars[i],bars[j]);
            int curr = w*h;

            area = max(area,curr);
        }
    }
    return area;
} */

//2. OPTIMAL FOR WATER USING TWO POINTER
int max(vector<int> bars){
    int i = 0,n = bars.size(), j = n-1;
    int w,h,area =0;
    while(i<j){
        w = j -i;
        h = min(bars[j],bars[i]);
        int curr = w*h;
        area = max(area,curr);
        bars[i] < bars[j] ? i++ : j--;
    }
    return area;
}
 int main(){
    vector<int> bars = {1,8,6,2,5,4,8,3,7};
    cout<<max(bars);
 }