#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~node(){
        cout << "Deleting node with data: " << data << endl;
    }
};

node* buildtree(){
    int data;
    cout << "Enter data for root node: ";
    cin >> data;
    if(data == -1) // Assuming -1 indicates a null node
        return NULL;
    
    node* root = new node(data);

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildtree();

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildtree();

    return root;
}
 
 void leveloreder_traversal(node* root){
  //create queue for storing nodes
  queue<node*> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    node* temp = q.front();
    q.pop();

    if(temp == NULL){
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

 void inorder(node* &root){
     
     //base case
     if(root == NULL)
     return;
    inorder(root->left);
    cout<<root-> data<<" ";
    inorder(root->right);
 }
 void postorder(node* &root){
    if( root == NULL)
     return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
 }
 void preorder(node* &root){
    if(root == NULL)
      return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
 }
 void reverseordertraversal(node* & root){
    //rln
    if(root == NULL)
    return;
   
    reverseordertraversal(root->right);
    reverseordertraversal(root->left);
    cout<<root->data<<" ";
 }

int main(){
    node* root = buildtree();
    if (root == NULL)
        cout << "Empty tree!" << endl;
    else
        cout << "Tree built successfully!" << endl;

    // Sample input sequence: 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
      
      cout<<"level order traversal"<<endl;
      leveloreder_traversal(root);

      cout<<"inorder traversal"<<endl;
      inorder(root);

      cout<<endl<<"postorder traversal"<<endl;
      postorder(root);

      cout<<endl<<"preorder traversal"<<endl;
      preorder(root);

      cout<<endl<<"reverseorder traversal"<<endl;
      reverseordertraversal(root);
    return 0;
}
