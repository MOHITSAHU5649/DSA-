#include<iostream>
#include<vector>
using namespace std;

void helper(vector<vector<int>> &mat,
int row, int col, string path,vector<string> &ans){ //,vector<vector<string>> &another
    int n = mat.size();
   
    if(row <0 || col<0 || row >=n || col >=n || mat[row][col] == 0 || mat[row][col] == -1){ //|| another[row][col] == true
        return;
    }

    if(row == n-1 && col == n-1){
        ans.push_back(path);
        return;
    }

   //another[row][col] = true;
    mat[row][col] = -1;
    helper(mat,row+1,col,path+"D",ans);
    helper(mat,row-1,col,path+"U",ans);
    helper(mat,row,col-1,path+"L",ans);
    helper(mat,row,col+1,path+"R",ans);

    mat[row][col] = 1;
    //another[row][col] = false;
}

vector<string> findpath(vector<vector<int>> &mat){
    vector<string> ans;
    string path = "";
    // vector<vector<string>> another(n,vector<bool>(n,false));
    helper(mat,0,0,path,ans);
    return ans;
}

int main(){
    vector<vector<int>> mat = {{1,0,0,0},
    {1,1,0,1},{1,1,0,0},{0,1,1,1}};

    vector<string> ans = findpath(mat);
    for(string path : ans){
        cout<<path<<endl;
    }
    return 0;
}