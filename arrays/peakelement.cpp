#include<iostream>
using namespace std;
int peakelement(int arr[], int n){
    int start = 0;
    int end = n-1;
    int mid = start + ((end-start)/2);

    while(start<end){
        if(arr[mid+1] > arr[mid]){
            start = mid+1;
        }
        else{
            end = mid;
        }
        mid = start + ((end-start)/2);
    };
        return start;
};

int main(){
    int arr[6] = {0,3,4,7,2,1};

    int answer = peakelement(arr,6);
    cout<<answer <<" ";
}