#include<iostream>
using namespace std;
int binarysearch(int arr[], int size, int key) {
    int start = 0;
    int end = size-1;

    int mid = (start+end)/2;

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        else if(key>arr[mid]){
            start=mid+1;
        }
        else{
            end =mid-1;
        }
        mid=(start+end)/2;  //mid=s+((e-s)/2) => this we actually have to use in order to avoid the case in which integer get out of range.
    }
    return -1;
}
int main(){
    int even[6] = {1,3,7,9,13,19};
    int odd[5] = {1,3,5,7,9};

    int index = binarysearch(even, 6, 19);
    cout<<index<<" ";
}