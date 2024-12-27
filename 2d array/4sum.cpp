//4 sum
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<vector<int>> foursumm(vector<int>& arr, int tar) {
        int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if(i>0 && arr[i] == arr[i-1]) continue;
        for(int j = i+1;j<n;j++ ){
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;
            int p = j+1, q= n-1;
           
            while (p<q)
            {
                long long sum = (long long)arr[i]+(long long)arr[j]+ 
                                (long long)arr[p]+ (long long)arr[q];

                                

            if(sum<tar){
                p++;
            }else if( sum >tar){
                q--;
            }else{
                ans.push_back({arr[i], arr[j], arr[p], arr[q]});
                p++,q--;
                while(p<q && arr[p] == arr[p-1]) p++;
                while (p < q && arr[q] == arr[q + 1]) q--; 
            }
            }
            
            
        }
    }
   
    return ans;
}

int main(){
vector<int> arr = {1, 0, -1, 0, -2, 2};
int tar = 0;
vector<vector<int>> another = foursumm(arr,tar);
for(int i =0;i<another.size();i++){
        for(int j = 0; j<another[i].size();j++){
            cout<<another[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}