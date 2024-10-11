#include<iostream>
using namespace std;
int partition(int arr[], int start, int end){
    int pivot = arr[start];
    int cnt = 0;
    for(int i = start+1;i<=end;i++){
        if(arr[i]<= pivot){
            cnt++;
        }
    }
    int pivotIndex = start + cnt;
    swap(arr[pivotIndex],arr[start]);
    int i = start;
    int j = end;
    while(i<pivotIndex && j > pivotIndex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quicksort(int arr[], int start, int end){
    if(start>=end){
        return ;
    }

    int p = partition(arr, start, end);

    quicksort(arr, start, p-1);
    quicksort(arr, p+1, end);
}
int main(){
    int arr[5] = {3,7,1,9,2};
    quicksort(arr, 0, 4);
    for(int i = 0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}

