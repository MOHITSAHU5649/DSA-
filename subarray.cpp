#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n = 5;
    int arr[5] = {0,1,2,3,4};
                // 1.  TO FIND THE SUBARRAYS 1.
    // for(int i =0;i<n;i++){
    //     for(int j = i;j<n;j++){
    //         for(int k = i;k<=j;k++){
    //             cout<<arr[k];
    //         }
    //         cout<<" ";
    //     }   
    //     cout << endl;
    // }
    // return 0;

            // 2.  TO FIND THE MAX SUB ARRAY 
    // int maxsum =INT16_MIN;
    // for(int i =0;i<n;i++){
    //     int currsum = 0;
    //      for(int j = i;j<n;j++){
    //         currsum+=arr[j];
    //         maxsum = max(currsum,maxsum);
    //            } }
    //            cout << maxsum;


               // 3. KADNE'S ALGORITHM
    int maxs = INT16_MIN;
    int curr = 0;
    for(int val:arr){
        curr += arr[val];
        maxs = max(curr,maxs);
if(maxs <= 0){
    maxs = 0;
}
    }
        cout<<maxs;
    
    return 0; }
