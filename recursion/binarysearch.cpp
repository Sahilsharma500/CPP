#include<iostream>
using namespace std;
int binarysearch(int *arr, int start, int end, int target){
    int mid = start + (end-start)/2;
    if(start>end){
        return 0;
    }
    if(arr[mid] == target){
        return mid;
    }
    else if(arr[mid]>target){
        binarysearch(arr, start, mid-1, target);
    }
    else if(arr[mid]<target){
        binarysearch(arr, mid+1, end, target);
    }
}
int main() {
    int start = 0;
    int end = 5;
    int arr[5] = {1,3,7,9,11};
    int target = 11;
    int result = binarysearch(arr, start, end , target);
    cout<<result;
}