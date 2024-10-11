#include<iostream>
using namespace std;
int power(int num, int pow){
    if(pow == 0){
        return 1;
    }
    if(pow == 1){
        return num;
    }
    int ans = 1;
    int fact = power(num, pow/2);
    if(num % 2 == 0){
        return ans * fact*fact;
    }
    else{
        return ans*num*fact*fact;
    }
    return ans;
}
int main(){
    int num = 2;
    int pow = 4;
    cout<<power(num,pow);
}