#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            this->data=d;
            this->left=left;
            this->right=right;
        }
};

node* createNode(node* root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    
    if(data == -1){
        return NULL;
    }
    cout<<"enter the value to the left of node : "<<endl;
    root->left= createNode(root->left);

    cout<<"enter the value to the right of node : "<<endl;
    root->right = createNode(root->right);
    return root;
}

int main(){
    node *root = NULL;
    root = createNode(root);
}