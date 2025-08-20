#include<iostream>
#include<vector>
using namespace std;


int sum(int matrix[][4], int n){
    int sum =0;
    for(int i =0;i<n;i++){
     sum += matrix[i][i]; // primary diagonal ka sum 
    
    if(i != n-1-i){
        sum += matrix[i][n-1-i]; // secondary daiagonalka sum jisme centre ellement ki do occurence nahi lete kebil ek hi lete hai 
    }
    }
    return sum ;

// for finding the centere index xjust use (n/2,n/2)

}

int main(){
    int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int rows =4;
    cout<<sum(matrix,rows);

    vector<vector<int>> mat= {{1,2,3},{4,5,6}};
    // to access number of rows we use mat.size()
    // to access number of coulmns we use mat[i].size()
    
    return 0;

}