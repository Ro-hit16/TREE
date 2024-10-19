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

   //constructor
   node(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
   }
};
node* buildtree(node* &root){
     cout << "enter data inserting in tree" << endl;
     int data;
     cin >> data;

     //base case
     if(data == -1){
       return NULL;
     }

     root = new node(data);

     cout << "enter data for inserting in left of " << data << endl;
     root->left = buildtree(root->left);
     cout << "enter data for inserting in right of " << data << endl;
     root->right = buildtree(root->right); 
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
  if(root == NULL){
    return;
  }
  //LNR
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void preorder(node* &root){
  if(root == NULL){
    return;
  }
  //NLR
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(node* &root){
  if(root == NULL)
    return;

 //LRN  
 postorder(root->left);
 postorder(root->right);
 cout << root->data << " ";
}
void reverse_order_traversal(node* &root){

  if(root == NULL){
    return;
  }
  reverse_order_traversal(root->right);
  cout<<root->data<<" ";            
  reverse_order_traversal(root->left);
}

void buildfromLevvelOrder(node* &root){
  queue<node*> q;

  cout << "enter data for root: " << endl;
  int data;
  cin >> data;
  root = new node(data);

  q.push(root);
  while(!q.empty()){
    node* temp = q.front();
    q.pop();
    cout << "enter left node for " << temp->data << endl;
    int leftdata;
    cin >> leftdata;

    if(leftdata != -1){
      temp->left = new node(leftdata);
      q.push(temp->left);
    }
      
    cout << "enter right node for " << temp->data << endl;
    int rightdata;
    cin >> rightdata;

    if(rightdata != -1){
      temp->right = new node(rightdata);
      q.push(temp->right);
    } 
  }
}

int main(){
  node* root = nullptr;
  root = buildtree(root);
  // // Sample input sequence: 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
  // cout << "Level-order traversal: " << endl;
  // leveloreder_traversal(root);

  cout << "Inorder traversal: " << endl;
  inorder(root);
  cout << endl;

  // cout << "Preorder traversal: " << endl;
  // preorder(root);
  // cout << endl;

  // cout << "Postorder traversal: " << endl;
  // postorder(root);
  // cout << endl;
  
  // cout<<"reverse oder traversal"<<endl;
  // reverse_order_traversal(root);
  return 0;
}
