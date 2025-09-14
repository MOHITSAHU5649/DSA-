#include<iostream>
#include<stack> // here we used the stl in the c++
using namespace std;

class solution{
    public:
    bool isValid(string s){
        stack<char> stc; // creted a stack using stl
        for(int i =0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {stc.push(s[i]);} // here we keep all the opening braces in the stack 

            else {
                if(stc.size() == 0) //here stack 0 matlb loi opening aaye he nahi hai 
                return false;            }


                if((stc.top() == '(' && s[i]== ')') || (stc.top() == '[' && s[i]== ']') ||
                (stc.top() == '{' && s[i]== '}')) {stc.pop();} // ab apagr koi index pe openeing thei to ab usk aka closing bhi dekh lo agar anhi mila to matlab valid nahi hai or false kar do and vice b=vers

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
