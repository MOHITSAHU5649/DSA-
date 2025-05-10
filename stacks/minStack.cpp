// leetcode 155
//


#include<iostream>
#include<stack>
#include<vector> 
using namespace std;

int main(){

// in thus we use the minVal variable to store and used a formiuale 2NO 2*new val - oldf val;
stack<long long int> s;
 long long int  minVal;
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minVal = val;
        }else{
            if(val < minVal){
                s.push((long long) 2 * val - minVal);
                minVal = val; 
            }else {
                s.push(val);
            } 
    }
    }
    
    void pop() {
        if(s.top() < minVal){
            minVal = 2* minVal - s.top();
        }

        s.pop();
    }
    
    int top() {
      if(s.top() < minVal){
        return minVal;
      }
      return s.top();
      
        
    }
    
    int getMin() {
        return minVal;
    }

// this is approach one where we use the pair 
 stack<pair<int,int>> s;
    void push(int val) {
        if(s.empty()){
            s.push({val,val});
        }else{
            int minVal = min(val,s.top().second);
            s.push({val,minVal});
        }
    }
    
    void pop() {
        s.pop();
        
    }
    
    int top() {
        return s.top().first;
        
    }
    
    int getMin() {
        return s.top().second;
        
    }

    return 0;
}