#include<iostream>
#include<queue>
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
};
void getLevelNode(node* root){
    queue<node* > main;
    main.push(root);
    main.push(NULL);

    while(!(main.empty())){
        node* temp = main.front();
        main.pop();

        if(temp==NULL){
            cout<<endl;
            if(!(main.empty())){
                main.push(NULL);
            }
        }
        else{
            cout<<temp<<endl;

            if(temp->left){
                main.push(temp->left);
            }
            if(temp->right){
                main.push(temp->right);
            }
        }
    }
}

int main(){
    node *root = NULL;
    root = createNode(root);

    //print tree with levels
    getLevelNode(root);
}