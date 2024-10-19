//longest comman acensitor
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
node* lca(node* root,int n1,int n2){
   if(root == NULL){
    return NULL;
     }
    if(root == n1 || root ==n2){
        return root;
    } 

     node* leftans =lca(root->left, n1,  n2);
    node* rightans =lca(root->right, n1,  n2);

    if(leftans !=NULL && rightans!= NULL){
        return root;
        
    }
    else if(leftans!= NULL && rightans == NULL){
        return leftans;
    }
    else if(leftans == NULL &&rightans != NULL){
        return rightans;

    }
    else{
        return NULL;
    }
    
}
int main(){

return 0;
}