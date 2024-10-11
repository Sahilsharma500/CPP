#include<iostream>
using namespace std;
void bubblesort(int *arr, int start, int end){
    if(start<=end){
    for(int i = start; i<=end;i++){
        if(arr[i]>arr[i+1] && i+1<=end){
            swap(arr[i], arr[i+1]);
        }
    }
    bubblesort(arr, start+1, end-1);
    }
}
int main(){
    int arr[5] = {3,1,6,9,4};
    int start = 0;
    int end = 4;
    bubblesort(arr, start, end);
    for(int i = 0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}