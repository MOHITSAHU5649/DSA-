
//tjis is leetcode 84, where multiple rectangle is given of differenrt sizes and then we have to find the areas by iedntifyig the widthe and the height of the columns for this 
// we use the right and left element using stack to find thart is ther exista any smaller number for creating a boundary
#include<iostream>
#include<stack>
#include<vector> 
using namespace std;

int main(){
 
    vector<int> heights;
        int n = heights.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        stack<int> s;

        for(int i = n-1;i>=0;i--){
            while(s.size() >0 && heights[s.top()] >= heights[i]){
                s.pop();
            }

            right[i] = s.empty() ? n :s.top();
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

         for(int i = 0;i<n;i++){
            while(s.size() >0 && heights[s.top()] >= heights[i]){
                s.pop();
            }

            left[i] = s.empty() ? -1 :s.top();
            s.push(i);
        }


        int ans =0;
        for(int i =0;i<n;i++){
            int width = right[i] - left[i] -1;
            int curr = heights[i] * width;
            ans = max(ans,curr);
        }

            cout<<ans; 
    

    return 0;
}