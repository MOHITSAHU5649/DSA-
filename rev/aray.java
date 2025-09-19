/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.util.*;
public class Main
{
    public static int singleElement(int arr[]){
        int start = 0;int n = arr.length;
        int end = arr.length -1;
        while(start <= end){
            int mid = start + (end - start/2);
            
            if(mid ==0 && arr[0] != arr[1]) return arr[mid];
            if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];
            if(mid ==n && arr[n-1] != arr[n-2] ) return arr[mid];
            
            if(mid %2 ==0){
                if(arr[mid] == arr[mid-1]){
                    end = mid-1;
                }else {
                    start = mid+1;
                }
            }else{
                if(arr[mid] == arr[mid-1]){
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }
        }
        return -1;
    }
    
    public static boolean  isvalid(int arr[], int mid, int n, int m){
        int studens = 1, pages =0;
        for(int i = 0;i<n;i++){
            if(arr[i] > mid){
                return false;
            }
            if(pages +  arr[i] <= mid){
                pages += arr[i];
            }else{
                studens++;
                pages = arr[i];
            }
        }
        return studens > m ? false : true;
    }
    
    public static int bookAllocated(int arr[], int n, int m){
        
        if(m > n) return -1;
        int sum =0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        int ans = -1;
        int start =0; int end = sum;
        while(start <= end){
            
            int mid = start+(end - start)/2;
            if(isvalid(arr,mid, n,m)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
    
    public static int painterProb(int arr[], int n, int m){
        int start =0, sum =0;
        for(int i =0;i<n;i++){
            sum += arr[i];
            start = Math.max(start, arr[i]);
            
        }
            int end = sum;
            int ans = -1;
            while(start <= end ){
                int mid = start + (end - start)/2;
                if(isvalid(arr,mid, n,m)){
                   ans = mid;
                    start = mid-1;
                }else{
                    end = mid+1;
                }
            }
        return ans;
    }
    
    public static boolean ispossible(int arr[], int mid, int n, int m){
        int cow = 1; 
        int pis = arr[0];
        for(int i =0;i<n;i++){
           if(arr[i] - pis >= mid){
               cow++;
               pis = arr[i];
           }
           if(cow == m){
               return true;
           }
            
        }
        return false;
    }
    public static int aggressiveCows(int arr[], int n, int m){
        Arrays.sort(arr); 
        
        int start =1, end = arr[n-1] - arr[0], ans = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(ispossible(arr,mid,n,m)){
                ans = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
    public static void swap(int arr[], int n, int m){
        int temp = arr[n];
        arr[n] =arr[m];
        arr[m] = temp;
    }
    
    public static void dutchNationalFlag(int arr[]){
        int n = arr.length;
        int mid =0, high = n-1, low =0;
        while(mid<= high){
            if(arr[mid] == 0){
                swap(arr,mid, low);
                mid++;
                low++;
            }else if(arr[mid] == 1){
                mid++;
            }else{
                swap(arr,high , mid);
                high--;
            }
        }
    }
    
	public static void main(String[] args) {
		System.out.println("Hello World");
		int arr[] = {0,1,0,1,2,0,1,1};
		int n = 5, m =3;
		//System.out.println(singleElement(arr));
		System.out.println(bookAllocated(arr, n,m));
		System.out.println(painterProb(arr,n,m));
		System.out.println(aggressiveCows(arr,n,m));
	
		dutchNationalFlag(arr);
		for(int k : arr){
		System.out.println(k);}
	}
}
