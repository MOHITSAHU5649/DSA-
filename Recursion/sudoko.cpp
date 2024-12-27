// it will give no output because we fisrt provide the sudoka unsolved to the board vactor
#include<iostream>
#include<vector>
using namespace std;

bool issafe(vector<vector<char>> &board, int row, int col, int dig){
        //1
        for(int i =0;i<9;i++){
            if(board[row][i] == dig){
            return false;
        }
        }

        //2
        for(int j =0;j<9;j++){
            if(board[j][col] == dig){
                return false;
            }
        }

        //3
        int srow = (row/3) * 3;
        int scol = (col/3) *3;

        // for(int i =srow,j =scol; i <3 && j<3;i++,j++){
        //     if(board[i][j] == dig){
        //         return false;
        //     }
        // }

        for(int i = srow;i<=srow+2;i++){
            for (int j = scol;j<=scol+2;j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }
        return true;
    }

    bool ssol(vector<vector<char>> &board,int row, int col){
        if(row == 9){
            return true;
        }

        int nextrow = row, nextcol = col+1;
        if(nextcol == 9){
            nextrow = row+1;
            nextcol = 0;
        }

        if(board[row][col] != '.'){
            return ssol(board,nextrow,nextcol);
        }

        for(char dig ='1';dig<='9';dig++){
            if(issafe(board,row,col,dig)){
            board[row][col] = dig;
            if(ssol(board,row,col)){
                return true;
            }

            board[row][col] = '.';
        }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        ssol(board,0,0);
        
    }

int main(){
        vector<vector<char>> board;
        solveSudoku(board);

        for(auto val : board){
        for(auto  k : val){
        cout<<k<<" ";}
        cout<<endl;
     }


    return 0;
}