//leetcode 54
#include<iostream>
#include<vector>
using namespace std;

vector<int> spiral(vector<vector<int>> &mat){
    int m = mat.size(), n = mat[0].size();
    int srow =0, erow = m-1, scol = 0,ecol = n-1;
    vector<int> ans;

    while(srow <= erow && scol <= ecol){
        for (int i = scol; i <= ecol; i++)
        {
            ans.push_back(mat[srow][i]);
        }

        for (int j = srow+1; j <= erow; j++)
        {
            ans.push_back(mat[j][ecol]);        }
        
        for (int k = ecol-1; k >= scol; k--)
        {
            if(srow == erow){
                break;
            }
            ans.push_back(mat[erow][k]);
        }

        for (int l = erow-1; l >= srow+1; l--)
        {
            if (scol == ecol)
            {
                break;
            }

            ans.push_back(mat[l][scol]);
            
        }
        
        srow++;erow--;scol++;ecol--;
        
    }
    return ans;
}

int main(){
    vector<vector<int>> mat ={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> another = spiral(mat);
    for(auto k : another){
        cout<<" " << k ;
    }
    return 0;
}