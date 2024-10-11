// #include<iostream>
// using namespace std;

// int main(){
//     int arr[6] = {0,1,2,2,3,4};

//     int key = 2;

//     int start = arr[0];
//     int end = arr[5];
//     int mid = start + ((end-start)/2);
//     int ans = -1;
//     while(start<=end){
//         if(arr[mid]==key){
//             ans = mid;
//             end = mid - 1;
//         }
//         else if(arr[mid] > key){
//             end = mid - 1;
//         }
//         else if(arr[mid] < key){
//             start = mid + 1;
//         }
//     }
//     cout <<ans<<" ";
// }

#include<iostream>
using namespace std;
int firstposition(int arr[], int n, int key){
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    while(start<=end){
        if(arr[mid] >= key){
            
        }
    }
}
int main(){
    int arr[6] = {0,1,2,2,3,4};
    int key = 2;


}