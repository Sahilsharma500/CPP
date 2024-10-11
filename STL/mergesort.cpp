#include<iostream>
using namespace std;

int main(){
    int arr1[5]={2,7,9,11,13};
    int arr2[3]={1,3,5};
    int arr3[8]={};

    int i = 0;
    int j = 0;
    int k = 0;
    while(j<3){
        if(arr1[i]<arr2[j] && i<5){
            arr3[k]=arr1[i];
            i++;
            k++;
        }
        else{
            arr3[k]=arr2[j];
            j++;
            k++;
        }
    }
    while(i<5){
        arr3[k]=arr1[i];
        i++;
        k++;
    }
    while(j<5){
        arr3[k]=arr1[j];
        j++;
        k++;
    }

    for(int i = 0;i<8;i++){
        cout<<arr3[i]<<" ";
    }

}