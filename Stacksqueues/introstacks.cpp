#include<iostream>
#include<queue>
using namespace std;

int main(){
    // deque<int> q;
    //basic stl of cpp queues
    // q.push_front(5);
    // q.push_front(8);
    
    // cout<<q.front()<<endl;
    // cout<<q.back()<<endl;

    // q.push_back(6);
    // cout<<q.back()<<endl;

    //Creating a queue
    queue<int> q;
    q.push(11);
    cout << "front of q is: " << q.front() << endl;
    q.push(15);
    cout << "front of q is: " << q.front() << endl;

    q.push(13);
    cout << "front of q is: " << q.front() << endl;

    cout << "size of queue is : " << q.size() << endl;

    q.pop();
    q.pop();
    q.pop();

    cout << "size of queue is : " << q.size() << endl;

    if(q.empty()) {
        cout << "Queue is empty " << endl;
    }
    else{
        cout << "queue is not empty " << endl;
    }
}