#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > rs, rs2;
		int l = 1;

		this->level(rs, 1, root);

		for(vector<vector<int> >::reverse_iterator iter = rs.rbegin(); iter != rs.rend(); iter++) {
			rs2.push_back(*iter);
		}

		return rs2;
    }

	void level(vector<vector<int> > &vec, int l, TreeNode* p) {
		if(p == NULL)
			return;
		if(vec.size() < l) {
			vector<int> ivec;
			vec.push_back(ivec);
		}
		vec[l-1].push_back(p->val);
		this->level(vec, l + 1, p->left);
		this->level(vec, l + 1, p->right);
	}
	
};


TreeNode* buildTree(int*, int, int);

int main(int argc, char const *argv[])
{
	int arr[] = {3,9,20,-1,-1,15,7,-1,-1,-1,-1,-1,8};

	TreeNode *phead = buildTree(arr, 0, 12);

	cout<<"层序遍历："<<endl;
	Solution *sol = new Solution;
	vector<vector<int> > rs = sol->levelOrderBottom(phead);
	for(vector<vector<int> >::iterator iter = rs.begin(); iter != rs.end(); iter++) {
		for(vector<int>::iterator iter2 = (*iter).begin(); iter2 != (*iter).end(); iter2++) {
			cout<<*iter2<<" ";
		}
		cout<<endl;
	}
	return 0;
}

TreeNode* buildTree(int *arr, int pos, int total) {
	if(pos > total || pos < 0 || arr[pos] == -1) {
		return NULL;
	}

	TreeNode *p = new TreeNode(arr[pos]);

	p->left = buildTree(arr, 2*pos + 1, total);
	p->right = buildTree(arr, 2*pos + 2, total);

	return p;
}


