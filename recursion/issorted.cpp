#include<iostream>
using namespace std;
bool isSorted(int *arr, int size){
    if(size == 0 || size == 1){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }
    else{
        isSorted(arr+1, size-1);
    }

}
int main() {
    int arr[5]= {1,5,3,7,2};
    int size = 5;
    isSorted(arr, size);
    cout<<isSorted(arr, size)<<endl;
}