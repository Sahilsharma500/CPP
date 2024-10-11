#include<iostream>
using namespace std;

int main(){
    
    
    int arr[5] = {1,2,3,4,5};
    int *p = &arr[0];
    cout<<&arr[0]<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;
}