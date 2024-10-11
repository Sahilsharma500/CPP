#include<iostream>
using namespace std;
void merge(int *arr, int start, int end){
    int mid = (start+end)/2;
    int len1 = mid-start+1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = start;
    for(int i = 0; i<len1;i++){
        first[i] = arr[k++];
    }
    k = mid+1;
    for(int i = 0; i<len2; i++){
        second[i] = arr[k++];
    }
    int index1 = 0;
    int index2 = 0;
    int newarrindex = start;
    while(index1<len1 && index2<len2){
        if(first[index1]>second[index2]){
            arr[newarrindex++] = second[index2++];
        }
        else{
            arr[newarrindex++] = first[index1++];
        }
    }
    while(index1<len1){
        arr[newarrindex++] = first[index1++];
    }
    while(index2 <len2){
        arr[newarrindex++] = second[index2++];
    }
}
void mergesort(int *arr, int start, int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);

    merge(arr, start, end);
}
int main() {
    int arr[5] = {1,9,3,6,4};
    mergesort(arr, 0, 4);
    for(int i = 0; i < 5 ;i++){
        cout<<arr[i]<<" ";
    }
}