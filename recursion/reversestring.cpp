#include<iostream>
using namespace std;

void reverse(string& str, int start, int end){
    if(start<=end){
    swap(str[start], str[end]);
    reverse(str, start+1, end-1);
    }
}

int main() {
    string str = "sahil";
    int start = 0;
    int end = 4;
    reverse(str, start, end);
    cout<<str<<" ";

    
}