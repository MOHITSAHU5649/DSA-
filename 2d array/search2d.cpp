// leetcode 74  and leetcode 240 variation 
#include<iostream>
#include<vector>
using namespace std;

// this is first approach
bool isfound(vector<vector<int>> &matrix, int midrow, int target){
    int m = matrix[0].size();
    int start =0, end = m-1;
    while (start <= end)
    {
        int mid = start +(end- start)/2;
        if(target == matrix[midrow][mid]){
            return true;
        }

        if(target < matrix[midrow][mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return false;
    
}

bool search(vector<vector<int>> &matrix, int target){
    int m = matrix.size(), n = matrix[0].size();
    int srow =0, erow =m-1;

    while(srow <= erow){
        int midrow = srow +(erow-srow)/2;
        if(target >= matrix[midrow][0] && target <= matrix[midrow][n-1]){
            return isfound(matrix,midrow,target);
        }

        if(target <matrix[midrow][0]){
            erow = midrow-1;
        }

        if(target > matrix[midrow][n-1]){
            srow = midrow+1;
        }
    }
    return false;
}

// this is second orr anothe varitaion 
bool search2(vector<vector<int>> &mat, int target){
    int m =mat.size(),n = mat[0].size();

    int s = 0, e = n-1;
    while(s < m && e >= 0){
        if(target == mat[s][e]){
            return true;
        }

        else if(target < mat[s][e]) {e--;}
        else {s++;}
    }
    return false;
}

int main(){
    vector<vector<int>> matrix= {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int target = 5;
    // cout<<search(matrix,target);

    vector<vector<int>> mat = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    cout<<search2(mat, target);
    return 0;
}