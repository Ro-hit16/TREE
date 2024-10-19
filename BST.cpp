#include<iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;


    //construtor
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node* insertdata_in_bst(node* &root,int data){
    if(root == NULL){
        root= new node(data);
        return root;
    }
    if(data < root->data){
        root->left = insertdata_in_bst(root->left,  data);
    }
    else{
        root->right =insertdata_in_bst(root->right, data);
    }
    return root;
}
void takeinput(node* &root){
    int data;
    cin>>data;

    while (data != -1) {
        insertdata_in_bst(root, data);
        cin>>data;
    
    }
} 
void inorder(node* &root){
    if(root ==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* &root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* &root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
void levelorder_traversal(node* &root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp =q.front();
        q.pop();
        if(temp ==NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
int main(){
node* root = NULL;
cout<<"enter data to creat bst"<<endl;
takeinput(root);


cout<<"BST is"<<endl;
levelorder_traversal(root);

cout<<endl<<"inorder traversal"<<endl;
inorder(root);

cout<<endl<<"preorder traversal"<<endl;
preorder(root);

cout<<endl<<"postorder traversal"<<endl;
postorder(root);

return 0;
}