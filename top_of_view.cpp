#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

// Define the structure of the tree node
struct node {
    int data;
    node* left;
    node* right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find the top view of the binary tree
vector<int> topview(node* root) {
    vector<int> ans;
    if (root == nullptr) {
        return ans;
    }

    map<int, int> m;
    queue<pair<node*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<node*, int> temp = q.front();
        q.pop();

        node* frontnode = temp.first;
        int hd = temp.second;

        if (m.find(hd) == m.end()) {
            m[hd] = frontnode->data;
        }

        if (frontnode->left) {
            q.push(make_pair(frontnode->left, hd - 1)); 
        }
        if (frontnode->right) {
            q.push(make_pair(frontnode->right, hd + 1)); 
        }
    }

   
    for (auto i : m) {
        ans.push_back(i.second);
    }
    return ans;
}

int main() {
    // Example usage:
    // Create a sample binary tree
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->left->right->right = new node(5);
    root->left->right->right->right = new node(6);

    // Find and print the top view of the binary tree
    vector<int> result = topview(root);
    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
