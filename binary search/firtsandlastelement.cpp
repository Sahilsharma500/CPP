#include<iostream>
using namespace std;

int main(){
    int arr[5] = {1,3,7,7,11};
    int start = 0;
    int end = 4;
    int mid = start + ((end-start)/2);
    int ans = 0;
    int target=7;
    while(start<end){
        if(arr[mid]==target){
            ans = mid;
            end = mid-1;
        }
        else if(arr[mid]<target){
            start = mid + 1;
        }
        else if(arr[mid]>target){
            end = mid - 1;
        }
        mid = start + ((end-start)/2);
    }
    cout<<ans;
}