
public class selection {
    
    public static void main(String[] args){
        int arr[] = {64,25,12,22,11};
        int n = arr.length; int min; int temp =0;

         for(int i =0;i<n;i++){
                min =i;
            for(int j =i+1;j<n;j++){
                if(arr[j] < arr[min]){
                    min = j;
                }
            }
                temp = arr[i];
                arr[i] = arr[min];
                arr[min]= temp;
            
         }

         for(int i =0;i<n;i++){
            System.out.print(arr[i]+" ");
         }
    }
}
