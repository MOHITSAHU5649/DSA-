 #include<iostream>
 #include<vector>
 using namespace std;
 //leetcode 88
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index= m+n-1, i = m-1, j= n-1;
        while(i>=0 && j>=0){

            if(nums1[i] >= nums2[j]){
                nums1[index--] = nums1[i--];
            }else{
                nums1[index--] = nums2[j--];
            }
        }
        while(j>=0){
            nums1[index--] = nums2[j--];
        }
        
    }


int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int n =3, m =3;
    merge(nums1,m,nums2,n);
    for(int k =0;k<m+n;k++){
        cout<<nums1[k];
    }
    }