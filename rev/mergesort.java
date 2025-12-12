public class mergesort{

    public static void merge(int arr[], int start, int mid, int end){
        int merged[] = new int[end - start +1];
        int a = start;
        int b = mid+1;
        int x =0;

        while(a <= mid && b <= end){
            if(arr[a] <= arr[b]){
                merged[x++] = arr[a++];
            }else{
                merged[x++] = arr[b++];
            }
        }

        while(a <= mid){
            merged[x++] = arr[a++];
        }

        while(b <= end){
            merged[x++] = arr[b++];
        }

        for(int i =0, j = start; i < merged.length;i++,j++){
            arr[j] = merged[i];
        }



    }


    public static void mergeSort(int arr[], int start, int end){
        if(start >= end){
            return;
        }
            int mid = start + ( end - start)/2;
             mergeSort(arr, start, mid);
             mergeSort(arr, mid + 1, end);
             merge(arr, start, mid, end);
    }

    public static void main(String[] args){
        int[] arr = {38, 27, 43, 3, 9, 82, 10};
        mergeSort(arr, 0, arr.length - 1);
        for(int num : arr){
            System.out.print(num + " ");
        }
    }

}