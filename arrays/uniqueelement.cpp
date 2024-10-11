#include<iostream>
using namespace std;

int main(){
    int arr[5] = {0,9,1,9,1};
    for(int i = 0;i<5;i++){
        for(int j = i+1;j<5;j++){
            if(arr[i]==arr[j] && arr[i] != 0){
                arr[i]=0;
                arr[j]=0;
            }
        }
    }
    int temp=0;
    for(int i = 0;i<5;i++){
        if(arr[i] !=0){
            temp=arr[i];
            break;
        }
    }
    cout<<temp<<" ";
}