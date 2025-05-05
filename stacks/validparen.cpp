#include<iostream>
#include<stack>
using namespace std;

class solution{
    public:
    bool isValid(string s){
        stack<char> stc;
        for(int i =0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {stc.push(s[i]);}

            else {
                if(stc.size() == 0)
                return false;            }


                if((stc.top() == '(' && s[i]== ')') || (stc.top() == '[' && s[i]== ']') ||
                (stc.top() == '{' && s[i]== '}')) {stc.pop();}

                else {
                    return false;
                }
        }


        return stc.size() == 0;
    }


};


int main(){
solution scl;
string str = "({[]})";

cout<<scl.isValid(str);

    return 0;
}
