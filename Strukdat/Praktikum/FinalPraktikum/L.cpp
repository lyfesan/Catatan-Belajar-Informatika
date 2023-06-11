#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int value) : data(value), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int value) {
	if (root == NULL) return new Node(value);
	if (value < root->data) root->left = insert(root->left, value);
	else if (value > root->data) root->right = insert(root->right, value);
	return root;
}

void maxVal(Node* node, int level, vector<int>& ans) {
	if (node == NULL) return;
	if (level >= ans.size()) {
    	ans.push_back(0);
	}
	ans[level] = max(ans[level], node->data);
	maxVal(node->left, level + 1, ans);
	maxVal(node->right, level + 1, ans);
}

int main() {
	Node* root = NULL;
	int value;
	while (cin >> value) {
    	root = insert(root, value);
	}
	vector<int> ans;
	maxVal(root, 0,ans);
	for(int i = 0; i < ans.size(); i++){
    	cout<<ans[i]<<endl;
	}
}