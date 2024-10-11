#include<iostream>
using namespace std;

int main() {
    char ar[20];
    cin>>ar;

    cout<<ar;
    cout<<endl;
    int count = 0;
    for(int i = 0; ar[i]!='\0'; i++){
        count++;
    }
    cout<<count;
    cout<<endl;

    for(int i=0;i<count/2;i++){
        swap(ar[i], ar[count-i-1]);
    }
    cout<<ar;
    cout<<endl;
}
