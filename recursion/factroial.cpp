#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0){
        return 1;
    }
    int fact = n*factorial(n-1);
    return fact;
    
}
int main(){
    int n = 5;
    int answer = factorial(n);
    cout<<answer<<endl;
}