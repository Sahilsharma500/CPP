#include<iostream>
using namespace std;

int main(){
   int arr[6] = {2,1,4,7,3,9};

    for(int i = 0; i< 5; i++){
        for(int j = i+1;j<6;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }

    for(int i = 0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}