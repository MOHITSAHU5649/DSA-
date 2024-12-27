#include<iostream>
#include<vector>
using namespace std;

bool isvalid(vector<int> &arr,int n, int m, int allowed){
    int stu =1, pages =0;
    for(int i =0;i<n;i++){
        if(arr[i] > allowed){
            return false;
        }

        if(pages + arr[i]<= allowed) {
            pages +=arr[i];
        }else{
            stu++;
            pages = arr[i];
        }
    }
return stu>m ? false:true;
}


int bookallocate(vector<int> &arr, int n, int m){
    if(m>n) return -1;
    int sum =0;
    for(int i =0;i<n;i++){
        sum+=arr[i];
    }
int start =0, end = sum,ans;
    while(start<= end){
        int mid = start +(end-start)/2;
        if(isvalid(arr,n,m,mid)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr ={2,1,3,4};
    int n = 4, m =2;
    cout<<bookallocate(arr,n,m)<<endl;
    return 0;
}