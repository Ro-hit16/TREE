#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class solution{
    public:
    void solve(node* root , int k,int count,vector<int>path){
        if(root == NULL){
            return;
        }
        path.push_back(root->data);

        solve(root->left,  k,count,  path);
         solve(root->right,  k,count,  path);
         int size =path.size();
         int sum =0;
         for(int i = size-1; i>=0;i--){
            sum +=path[i];
            if(sum ==k){
                count++;
            }
          

         }
        path.pop_back();
    }

    int sumk(node* root,int k){
        vector<int>path;
        int count=0;
        solve(root,k,count,path);
        
    }
};
int main(){

return 0;
}