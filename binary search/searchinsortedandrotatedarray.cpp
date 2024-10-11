#include<iostream>
using namespace std;

int main(){
    int arr[5]= {7,9,1,2,3};
    int target = 9;
    int ans = 0;

    int start = 0;
    int end = 4;
    int mid = start + (end-start)/2;
    while(start<=end){
        if(arr[mid]>=arr[0]){
           if(arr[mid]==target){
                ans = mid;
            }

        }
        else{
             if(arr[mid]==target){
                ans = mid;
            }
            else if(arr[mid]>target){
                end = mid - 1;
            }
            else if(arr[mid]<target){
                start = mid+1;
            }
        }
    }
    cout<<ans;
}