#include<iostream>
using namespace std;

class node{
public:
 int data;
 node* left;
 node* right;

 node(int data){
    this->data =data;
     this->left = NULL;
    this-> right =NULL;

 }

 ~node(){

 }
};
node* buildtree(node* root){
    cout<<"enter  data for  root data"<<endl;
    int data;
    cin>>data;

    
    if(data == -1){
        return NULL;
    }
       root = new node(data);

    cout<<"enter data for inserting in left node of"<<data<<endl;
    root->left = buildtree(root->left);
    cout<<"enter data for inserting in right node of"<<data<<endl;
    root->right = buildtree(root->right);

    return root;

}
int main(){
    node* root =NULL;
     root = buildtree(root);
}