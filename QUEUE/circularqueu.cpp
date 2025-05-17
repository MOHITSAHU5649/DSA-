#include<iostream>
#include<queue>
using namespace std;

class cirQueu{
    int * arr;
    int currsum, cap;
    int f,r;

    public:
        cirQueu(int size){
            cap = size;
            currsum =0;
            arr = new int[cap];
            f =0;
            r = -1;
        }


        void push(int data){
            if(currsum == cap ){
                cout<<"is full";
                return ;
            }else{
                r = (r+1)%cap;
                arr[r] = data;
                currsum++;
            }
        }

        void pop(){
            if(empty()){
                cout<<"empty";
                return;
            }
            f = (f+1)%cap;
            currsum--;
        }

        int front(){
            if(empty()){
                cout<<"empty";
                return -1;
            }

            return arr[f];
        }

        bool empty(){return currsum == 0;}

        void print(){
            for(int i =0;i<cap;i++){
                cout<<arr[i]<<" ";
            }cout<<endl;
        }

};

int main(){
    cirQueu c(3);
    c.push(1);
    c.push(2);
    c.push(3);
    c.pop();
    c.push(34);


 c.print();// insertion order 
 while(!c.empty()){// this will help to show the real circular output
    cout<<c.front()<<" ";
    c.pop();
 }
    return 0;
}