#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
       this ->data = data;
       this-> left =NULL;
       this ->right =NULL;

    }

};

void traverseright(node* &root , vector<int>&ans){
    if(root == NULL || root->right == NULL && root->left ==NULL){
         return;
    }
     
     ans.push_back(root-> data);
     if(root->left){
        traverseright(root->right,ans);

     }
     else{
        traverseright(root->left, ans);
     }

    
    
}

void leafnode(node* root , vector<int>&ans){
    if(root == NULL){
        return;
    }
    if(root->right == NULL && root->left == NULL){
        ans.push_back(root->data);
    }
    leafnode(root->right, ans);
    leafnode(root->left, ans);

}
void traverseleft(node* root,vector<int>&ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }
    if(root->left){
        traverseleft(root->left,ans);
    }
    else {
    traverseleft(root->left,ans);
    }

    ans.push_back(root->data);


}
vector <int> boundary(node* root){
    vector<int>ans;

    if(root == NULL){
      return ans;
    }
      ans.push_back(root->data); 
     traverseright(root->right, ans);
    leafnode(root->right, ans);
    leafnode(root->left, ans);
    traverseleft(root->left, ans);

    return ans;

}
int main(){
  node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> result = boundary(root);

    cout << "Boundary of the binary tree in the clockwise direction starting from the right side is: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
return 0;
}