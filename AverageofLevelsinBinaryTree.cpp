#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<double> averageOfLevels(TreeNode* root) {
	vector<double> res;
	queue<TreeNode *> q;
	double temp;
	TreeNode *cur = root;
	TreeNode *temp1;
	q.push(cur);
	while(!q.empty()) {
		int count = q.size();
		temp = 0;
		int count1 = count;
		while(count > 0) {
			temp1 = q.front();
			temp += temp1->val;
			q.pop();
			if(temp1->left)
				q.push(temp1->left);
			if(temp1->right)
				q.push(temp1->right);
			count --;
		}
		res.push_back(temp/count1);
	}
	return(res);
}

int main()
{
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	vector<double> res = averageOfLevels(root);

	return (0);
}
