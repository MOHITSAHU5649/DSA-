#include<iostream>
#include<vector>
using namespace std;

bool issafe(vector<string>& board, int row,int col,int n){
        //1
        for(int i =0;i<n;i++){
            if(board[row][i] == 'Q'){
                return false;
            }
        }
        
        //2
        for(int j =0;j<n;j++){
            if(board[j][col] == 'Q'){
                return false;
            }
        }

        //3
        for(int i = row-1, j = col-1; i>=0 && j>=0; i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        //4
        for(int i = row-1,j= col+1;i>=0 && j<n; i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }

    void nqueen(vector<string>& board, int row, int n, vector<vector<string>>& ans){
        if(row  == n){
            ans.push_back({board});
            return;
        }

        for(int i = 0;i<n;i++){
            if(issafe(board,row,i,n)){
                board[row][i] = 'Q';
                nqueen(board,row+1,n,ans);
                //backtrack
                board[row][i] = '.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;

        nqueen(board,0,n,ans);
        return ans;
    }

int main(){
    int n = 4;
vector<vector<string>> another = solveNQueens(n);
for(auto val : another){
        for(auto  k : val){
        cout<<k<<" ";}
        cout<<endl;
     }
    return 0;
}