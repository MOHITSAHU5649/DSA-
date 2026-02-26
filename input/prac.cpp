#include<bits/stdc++.h>
using namespace std;

vector<int> input_array_format(){
    vector<int> arr;
    string input;
    getline(cin,input);

  input.erase(remove(input.begin(),input.end(), '['), input.end());
  input.erase(remove(input.begin(),input.end(), ']'), input.end());

  replace(input.begin(),input.end(), ',',' ');

    stringstream ss(input);
    int num;
    while(ss>>num){
        arr.push_back(num);
}
    return arr;
}

void bubble_sort(vector<int> &arr){
    int n = arr.size();
    bool status = false;
    for(int i =0;i<n;i++){
        status = false;
        for(int j = 0;j<n-i-1;j++){
            if(arr[j] < arr[j+1]){
                swap(arr[j],arr[j+1]);
                status = true;
            }
        }
        if(status == false){
            break;
        }
    }

    for(int n : arr){
        cout<<n<<" ";
    }
}

void  insertion_sort(vector<int> &arr){
    int n = arr.size();
    int key,j;
    for(int i =1;i<n;i++){
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j] < key){
            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = key;
    }

   for(int n:arr){
    cout<<n<<" ";
   }
}

void selection_sort(vector<int> &arr){
    int n = arr.size();

    for(int i =0;i<n;i++){
        int min = i;
        for(int j =i+1;j<n;j++){
            if(arr[j] < min){
                min = j;
            }
        }
        swap(arr[i], arr[min]);

    }

    for(auto n:arr){
        cout<<n<<" ";
    }
}

void merge(vector<int> &arr, int start, int end, int mid){
    int a = start;
    int b = mid+1;
    vector<int> temp;

    while(a<= mid && b <= end){
        if(arr[a] <= arr[b]){
            temp.push_back(arr[a]);
            a++;
        }else{
            temp.push_back(arr[b]);
            b++;
        }
    }

    while(a<= mid){
        temp.push_back(arr[a++]);
}
    while(b <= end){
        temp.push_back(arr[b++]);
    }

    for(int i = start;i<= end;i++){
        arr[i] = temp[i-start];
    }

 

}

void merge_sort(vector<int> &arr, int start, int end){
    if(start >= end){
        return;
    }

    int mid = start + (end - start)/2;

    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);
merge(arr,start,end,mid);

}

int partition(vector<int> &arr, int start, int end){
    int pivot = arr[end];
    int i = start -1;

    for(int j =start;j<end;j++){
        if(arr[j] < pivot){
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
}


void quicksort(vector<int> &arr, int start, int end){
    if(start < end){
        int pivot = partition(arr, start, end);
    

    quicksort(arr,start, pivot-1);
    quicksort(arr,pivot+1,end);}
}

int linearsearch(vector<int> &arr, int target){
    for(int i =0;i<arr.size();i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int binarysearc(vector<int> &arr, int target){
    int left = 0;
    int right = arr.size()-1;

    while(left <= right){
         int mid = left + (right - left)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            left = mid +1;
        }
        else{
            right = mid-1;
        }
    }

    return -1;
}

vector<int> inpt_Array(){
    vector<int> arr;
    string input;
    getline(cin,input);

    input.erase(remove(input.begin(),input.end(), ']'), input.end());
    input.erase(remove(input.begin(),input.end(), '['), input.end());

    replace(input.begin(), input.end(),',',' ');

    stringstream ss(input);
    int num;
    while(ss>>num){
        arr.push_back(num);
    }
    return arr;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   // cin.ignore(numeric_limits<streamsize> :: max(), '\n');

    vector<int> arr = input_array_format();
   //quicksort(arr, 0,arr.size()-1);

   cout<<binarysearc(arr,5);
    return 0;
}