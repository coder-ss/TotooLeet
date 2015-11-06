#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<string> svec;

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) {
            return this->svec;
        }

        this->binaryTreePaths(root, "");

        return this->svec;
    }

    void binaryTreePaths(TreeNode* node, string s) {
        if(s == "") {
            s += this->getValue(node);
        } else {
            s += "->" + this->getValue(node);
        }

        if(node->left == NULL && node->right == NULL) {
            this->svec.push_back(s);
            return;
        }

        if(node->left) {
            this->binaryTreePaths(node->left, s);
        }

        if(node->right) {
            this->binaryTreePaths(node->right, s);
        }
    }

    string getValue(TreeNode* node) {
        char buffer[50];
        sprintf(buffer, "%d", node->val);

        return string(buffer);
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution* sol = new Solution;

    vector<string> svec = sol->binaryTreePaths(root);

    for(vector<string>::iterator it = svec.begin(); it != svec.end(); ++it) {
        cout<<*it<<endl;
    }

    return 0;
}