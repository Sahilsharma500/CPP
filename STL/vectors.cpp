#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector <int> v;

    cout<<v.capacity();

    v.push_back(5);

    cout<<v.capacity();

    v.clear();

    cout<<v.capacity();

    v.push_back(5);

    for(int i :v){
        cout<<i<<"";
    }


}