#include<iostream>
#include<array>
using namespace std;

int main() {
    array<int, 4> a = {1,2,3,4};

    for(int i = 0; i<4;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    cout<<a.at(2)<<" "; // to get a particular element at aparticular position
    cout<<endl;

    cout<<a.empty()<<" ";  //check whether he array is empty or not

    cout<<a.front()<< " "; //1st element;

    cout <<a.back()<<" ";  // last element;
}