#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;
class node {

public:
  int data;
  node *left;
  node *right;

  node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

vector<int> verticalorder(node *root) {
  map<int, map<int, vector<int>>> nodes;
  queue<pair<node *, pair<int, int>>> q;
  vector<int> ans;

  if (root == NULL) {
    return ans;
  }
  q.push_back(make_pair(root, make_pair(0, 0)));

  while (!q.empty()) {
    pair<node *, pair<int, int>> temp = q.front(); 

    node *frontnode = temp.first;
    int hd = temp.second.first; // hd = horizontal value
    int level = temp.second.second;

    nodes[hd][level].push_back(frontnode->data);

    if (frontnode->left) {
      q.push_back(make_pair(frontnode->left, (make_Pair(hd - 1, level + 1))));
    }
    if (frontnode->right) {
      q.push_back(make_pair(frontnode->right, make_pair(hd + 1, level + 1)));
    }
  }
  for (auto i : nodes) {
    for (auto j : i.second) {
      for (auto k : j.second) {
        ans.push_back(k);
      }
    }
  }
  return ans;
}
int main() { return 0; }