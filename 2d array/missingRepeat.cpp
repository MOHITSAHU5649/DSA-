// leetcode 2965
#include<iostream>
#include<vector>
#include <unordered_set>
using namespace std;

vector<int> mr(vector<vector<int>>& grid) {
        unordered_set<int> m;
        vector<int> ans;
        int  n = grid.size();
        int a,b;
        int expectedsum =0, actualsum =0;
        for(int i =0;i<n;i++){
            for(int j = 0; j<n;j++){
                actualsum += grid[i][j];
        if(m.find(grid[i][j]) != m.end()){
                a = grid[i][j];
                ans.push_back(a);
        }
        m.insert(grid[i][j]);
        }
        }

        expectedsum = (n*n) * (n*n + 1)/2;
        b = expectedsum +a- actualsum;
        ans.push_back(b);
        return ans;
    }

    int main(){
        vector<vector<int>> grid = {{1,3},{2,2}};
        vector<int> m = mr(grid);
        for(auto k : m){
            cout<<k<<" ";
        }

        return 0;
    }