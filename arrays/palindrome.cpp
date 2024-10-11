#include<iostream>
using namespace std;
bool ispalindrome(char name[], int n){
    for(int i = 0;i<n/2;i++){
        if(name[i] != name[n-i-1]){
        return 0;
        }
        else{
            i++;
        }
        
    }
    return 1;
}
int main(){
    char name[20];

    cin>>name;

    int count = 0;
    for(int i = 0;i!='\0';i++){
        count++;
    }

    if(ispalindrome(name, count)){
        cout<<"given number is a palindrome number"<<" ";
    }
    else{
        cout<<"given number is not a palindrome number";
    }
}