import java.util.*;
public class dmatrix
{
    public static boolean linearSearch(int arr[][], int target){
        for(int i =0;i<arr.length;i++){
            for(int j =0;j<arr[0].length;j++){
                if(arr[i][j] == target){
                    return true;
                }
            }
        }
        return false;
    }
    
    public static int sumMax(int arr[][]){
        int ans =0;
        for(int i =0;i<arr.length;i++){
            int sum = 0;
            for(int j = 0;j<arr[0].length;j++){
                sum += arr[j][i];
            }
             ans = Math.max(sum,ans);
        }
        return ans;
    }
    
    public static int daigonalSum(int arr[][]){
        int sum =0;
        int n = arr.length;
        for(int i =0;i<arr.length;i++){
            sum += arr[i][i];
            
            if(i != n-i-1){
                sum += arr[i][n-i-1];
            }
        }
        return sum;
    }
    
    public static boolean binarySearch(int arr[][], int target){
        int n = arr.length;
        int m = arr[0].length;
        int start = 0; int end = n-1;
        while(start < end){
            int mid = start+ (end - start)/2;
            if(arr[mid][0] <= target && target <= arr[mid][m-1]){
                return bs(arr,target,mid);
            }else if(arr[mid][0] > target){
                end = mid-1; 
            }else{
                start = mid+1;
            }
        }
        return false;
    }
    
    public static boolean bs(int arr[][],int target, int mid){
        int start =0;
        int end = arr[mid].length-1;
        
        while(start < end){
            int middle = start + (end - start)/2;
            
            if(arr[mid][middle] == target){
                return true;
            }else if( arr[mid][middle] < target){
                start = middle +1;
            }else {
                end = middle-1;
            }
        }
        return false;
    }
    
    public static boolean search(int arr[][], int target){
        int n = arr.length; int m = arr[0].length-1;
        int row =n-1; int col = 0;
        while(row < n && col <= m){
            if(target == arr[row][col]){
                return true;
            }else if ( target < arr[row][col]){
                row--;
            }else {
                col++;
            }
        }
        return false;
    }
    
    public static ArrayList<Integer> spiralMatrix(int arr[][]){
        int n = arr.length;
        ArrayList<Integer> al = new ArrayList<>();
        int m = arr[0].length;
        int sr = 0, er = n-1;
        int sc= 0, ec = m-1;
        while(sr <= er && sc <= ec){
            for(int i = sc;i<=ec;i++){
                al.add(arr[sr][i]);
            }
            
            for(int j = sr+1;j<=er;j++){
                al.add(arr[j][ec]);
            }
            
            for(int k = ec-1;k >= sc;k--){
                if(sr == er){
                    break;
                }
                al.add(arr[er][k]);
            }
            
            for(int l = er-1;l >= sr+1;l--){
                if(sc == ec){
                    break;
                }
                al.add(arr[l][sc]);
            }
            sr++;sc++;
            ec--;er--;
        }
        return al;
    }
    
    public static ArrayList<Integer> twoSum(int arr[],int target){
        HashMap<Integer,Integer> map = new HashMap<>();
        ArrayList<Integer> al = new ArrayList<>();
        
        for(int i =0;i<arr.length;i++){
            int first = arr[i];
            int sec = target - first;
            
            if(map.containsKey(sec)){
               
                al.add(map.get(sec)); al.add(i);
                break;
            }
            map.put(first ,i);
        }
        return al;
    } 
    
    public static ArrayList<Integer> msisingDuplicate(int arr[][]){
        HashSet<Integer> set = new HashSet<>();
        ArrayList<Integer> al = new ArrayList<>();
        int actualsum =0;int a =0 ;int n = arr.length;
        
        for(int i = 0;i<arr.length;i++){
            for(int j =0;j<arr[0].length;j++){
                actualsum += arr[i][j];
                if(set.contains(arr[i][j])){
                    a = arr[i][j];
                    al.add(arr[i][j]);
                }
                set.add(arr[i][j]);
            }
        }
        
        int totalsum = (n*n) *(n*n+1)/2;
        int b = totalsum +a - actualsum;
        al.add(n);
        return al;
    }
    
    public static int duplicate(int arr[]){
        int slow = arr[0];
        int fast = arr[0];
        
        do{
            slow = arr[slow];
            fast = arr[arr[fast]];
        }while(slow != fast);
        
        slow = arr[0];
        
        while(slow != fast){
            slow = arr[slow];
            fast = arr[fast];
        }
        
        return fast;
    }
    
    public static ArrayList<ArrayList<Integer>> threeSum(int arr[]){
        ArrayList<ArrayList<Integer>> al = new ArrayList<>();
        Arrays.sort(arr);
        for(int i =0;i<arr.length;i++){
            if(i > 0 && arr[i] == arr[i-1]) continue;
            
            int j = i+1;
            int k = arr.length-1;
            while(j<k){
                int sum = arr[i] +arr[j] +arr[k];
                if(sum == 0){
                    al.add(new ArrayList<> (Arrays.asList(arr[i],arr[j],arr[k])));
                    j++;k--;
                    while(j <k  && arr[j] == arr[j-1]){j++;}
                }else if(sum < 0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return al;
    }
    
	public static void main(String[] args) {
		int arr[][] = {{9,1,7},{8,9,2},{3,4,6}};
		int arr1[]  = {-1,0,1,2,-1,4}; int tar = 9;
		int target = 5;
	//	System.out.println(linearSearch(arr,target));
	//	System.out.println(sumMax(arr));
	//	System.out.println(daigonalSum(arr));
// 		System.out.println(binarySearch(arr, target));
// 		System.out.println(search(arr,target));
// 		System.out.println( spiralMatrix(arr));
// 		System.out.println(twoSum(arr1,tar));
// 		System.out.println(msisingDuplicate(arr));
	//	System.out.println(duplicate(arr1));
		System.out.println(threeSum(arr1));
	}
}
