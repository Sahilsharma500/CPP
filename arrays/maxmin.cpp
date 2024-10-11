#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    
    int arr[100];

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int num=INT_MIN;
    for(int i = 0 ; i<5;i++){
        if(arr[i]>num){
            num=arr[i];
        // num = max(num, arr[i]); // this line could be perfect replication of above lines.
        }

        else{
            continue;
        }
    }
    cout<<num<<endl;
}