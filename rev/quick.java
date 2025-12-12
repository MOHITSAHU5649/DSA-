public class quick{

    public static int partition(int arr[], int start, int end){
        int pivot = arr[end];
        int i = start -1;

        for(int j =start;j< end;j++){
            if(arr[j] < pivot ){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        i++;
        int temp = arr[i];
        arr[i] = arr[end];  
        arr[end] = temp;
        return i;
    }


    public static void quicksort(int arr[], int start, int end){
        if(start < end){
            int pivindex = partition(arr, start, end);

            quicksort(arr, start, pivindex - 1);
            quicksort(arr, pivindex + 1, end);
        }
    } 




    public static void main(String [] args){
        int[] arr = {38, 27, 43, 3, 9, 82, 10};
        quicksort(arr, 0, arr.length-1);
        for(int num : arr){
            System.out.print(num + " ");
        }
    }
}