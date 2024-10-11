#include<iostream>
#include<vector>
using namespace std;

vector <int> reverse(vector<int> v){
    int s = 0;
    int e = v.size()- 1;
    while(s<=e){
        swap(v[s], v[e]);
        s++;e--;
    }
    return v;
}

void print(vector<int> c){
    for(int i:c){
        cout<<i<<" ";
    }
}

int main() {
    vector<int> v;

    v.push_back(2);
    v.push_back(5);
    v.push_back(1);
    v.push_back(9);
    v.push_back(3);

    vector<int> c = reverse(v);
    print(c);
}