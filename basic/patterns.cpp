#include<iostream>
using namespace std;

int main(){
    //1234
    //1234
    //1234
    //1234
    // int n;
    // cin>>n;
    // int i=1;
    // while(i<=n){
    //     int j=1;
    //     while(j<=n){
    //         cout<<j<<" ";
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }

    // 3 2 1
    // 3 2 1
    // 3 2 1
    // int n;
    // cin>>n;

    // int i=1;
    // while(i<=n){
    //     int j=1;
    //     while(j<=n){
    //         cout<<n-j+1<<" ";
    //     j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }
    // 1
    // 2 3
    // 3 4 5
    // 4 5 6 7
    // 5 6 7 8 9

    // int n;
    // cin>>n;

    // int i = 1;
    // while(i<=n){
    //     int j = 1;
    //     int value = i;
    //     while(j<=i){
    //         cout<<value<< " ";
    //         value++;
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }
    //1
    //2 1
    //3 2 1
    //4 3 2 1
    //5 4 3 2 1

    // int n;
    // cin>>n;

    // int i = 1;
    // while(i<=n){
    //     int j = 1;
    //     while(j<=i){
    //         cout<<i-j+1<<" ";
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }

    // int n;
    // cin >>n;

    // int i = 1;
    // while(i<=n){
    // char a = 'A' + i - 1;
    // int j = 1;
    // while(j<=n){
    //     cout<<a<<" ";
    //     j++;
    // }
    // cout<<endl;
    // i++;
    // }
    // int n;
    // cin >>n;

    // int i = 1;
    // while(i<=n){
    // int j = 1;
    // while(j<=n){
    // char a = 'A' + j - 1;
    //     cout<<a<<" ";
    //     j++;
    // }
    // cout<<endl;
    // i++;
    // }

    // int n;
    // cin >>n;

    // int i = 1;
    // char a = 'A';
    // while(i<=n){
    // int j = 1;
    // while(j<=n){
    //     cout<<a<<" ";
    //     a=a+1;
    //     j++;
    // }
    // cout<<endl;
    // i++;
    // }

    // int n;
    // cin>>n;

    // int i = 1;
    // while(i<=n){
    //     int j=1;
    //     char a = 'A' + i - 1;
    //     while(j<=n){
    //         cout<<a<<" ";
    //         a++;
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }

    //A
    //BB
    //CCC
    //DDDD

    // int n;
    // cin>>n;

    // int i = 1;
    // while(i<=n){
    //     char a = 'A' + i - 1;
    //     int j = 1;
    //     while(j<=i){
    //         cout<<a<<" ";
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }

    //A
    //B C 
    //D E F
    //G H I J

    // int n;
    // cin>>n;

    // char a = 'A';
    // int i = 1;
    // while(i<=n){
    //     int j = 1;
    //     while(j<=i){
    //         cout<<a<<" ";
    //         a++;
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }

    //D
    //C D 
    //B C D
    //A B C D

    // int n;
    // cin>>n;

    // int i = 1;
    // while(i<=n){
    //     char a = 'A' + n - i;
    //     int j = 1;
    //     while(j<=i){
    //         cout<<a<<" ";
    //         a++;
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }
    //    *
    //   **
    //  ***
    // ****
    //***** 

    // int n;
    // cin>>n;

    // int i = 1;
    // while(i<=n){
    //     int space = n-i;
    //     int star = 1;
    //     int j = 1;
    //     while(space){
    //         cout<<" ";
    //         space--;
    //     }
    //     while(star<=i){
    //         cout<<"*";
    //         star++;
    //     }
    //     cout<<endl;
    //     i++;
    // }

    //***** 
    //**** 
    //***
    //**
    //*

    // int n;
    // cin>>n;

    // int i=1;
    // while(i<=n){
    //     int j = 1;
    //     while(j<= n-i+1){
    //         cout<<"*"<<" ";
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }

    //****
    // ***
    //  **
    //   *

    int n;
    cin>>n;

    int i = 1;
    while(i<=n){
        int space = 0;
        int star = n-i+1;
        while(space<=i-1){
            cout<<" ";
            space++;
        }
        while(star>0){
            cout<<i;
            star--;
        }
        cout<<endl;
        i++;
    }

    
}