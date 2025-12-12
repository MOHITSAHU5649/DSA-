public class insertion{

    public static void insertionMethod(int arr[]){
        
        int key, j;
        for(int i =1;i<arr.length;i++){

            key = arr[i];
            j = i-1;

            while(j>= 0 && arr[j] > key){
                arr[j+1] = arr[j];
                j = j-1;
            }
            arr[j+1] = key;
        }

        for(int i =0;i<arr.length;i++){
            System.out.println(arr[i] + " ");
        }

    }

    public static void main(String[] args){
        int arr[] = {64,25,12,22,11};
        insertionMethod(arr);
    }

}