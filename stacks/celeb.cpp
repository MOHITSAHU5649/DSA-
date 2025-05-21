// this is the clebrity problem in which we have to find out whiuch is the celebrity whcih is known by everyone but he doesnot knoe anyone \
 


#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int getCele(vector<vector<int>> arr){
    stack<int> s;
    int n = arr.size();

    for(int i =0;i<n;i++){
        s.push(i);
    }

    while(s.top() > 1){
        int i = s.top();
        s.pop();

        int j = s.top();
        s.pop();

        if(arr[i][j] == 0){
            s.push(i);
        }else{
            s.push(j);
        }
    }

    int celeb = s.top();

     for(int i =0;i<n;i++){
        if((i != celeb) && (arr[i][celeb] == 0 || arr[celeb][i] == 1)){
            return -1;
        }
     }

     return celeb;

}


int main(){

    vector<vector<int>> arr = {{0,1,0}, {0,0,0} , {0,1,0}};
    int ans = getCele(arr);
    cout<<ans;

    return 0;
}

