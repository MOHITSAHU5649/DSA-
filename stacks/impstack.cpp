#include<iostream>
#include<vector> 
#include<list>
#include<stack>

using namespace std;

class stackVec{
    //using the vector first aproach 
    vector<int> vec;
    public:

    void push(int val){
        vec.push_back(val);
    }

    void pop(){
        vec.pop_back();
    }

    int top(){
        return vec[vec.size() -1];
    }

    bool empty(){
        return vec.size() == 0;
    }
};

class Stack{
    list<int> ll;
    public:
    void push(int val){
        ll.push_front(val);
    }

    void pop(){
        ll.pop_front();
    }

    int top(){
        return ll.front();
    }

    bool empty(){
         return ll.size() == 0;
    }


};


int main(){
    stackVec s;
    Stack st;
    s.push(10);
    s.push(20);
    s.push(30);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }


cout<<"second";
    st.push(10);
    st.push(20);
    st.push(30);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    //third using the stack in stl
    stack<int> stc;
    //niw usint the same functions and logic to use it 


    return 0;
}