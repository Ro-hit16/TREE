#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(node* root,int sum,int &maxsum,int len,int &maxlen){
    if(root == NULL){
        if(len > maxlen){
            maxlen = len;
            maxsum = sum;
        }
        else if(len == maxlen){
            maxsum = max(sum,maxsum);
        }
        return;
    }
    sum = sum + root->data;

    solve(root->left,  sum, maxsum, len+1, maxlen);
    solve(root->right, sum, maxsum, len+1, maxlen);
}
int main(){

return 0;
}