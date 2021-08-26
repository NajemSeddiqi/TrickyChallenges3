#pragma once
#include <vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class EvenValuedGrandParents
{
public:
	void SumNodes(TreeNode* root, int& sum, int level) {
		if (root == nullptr) return;

		if (level == 2)
			sum += root->val;

		SumNodes(root->left, sum, ++level);

		SumNodes(root->right, sum, level);
	}

	void Delve(TreeNode* root, std::vector<TreeNode*>& nodes) {
		if (root == nullptr) return;

		if (root->val % 2 == 0)
			nodes.emplace_back(root);

		Delve(root->left, nodes);

		Delve(root->right, nodes);
	}

	int sumEvenGrandparent(TreeNode* root) {
		int sum = 0;
		std::vector<TreeNode*> nodes;
		Delve(root, nodes);

		for (auto& i : nodes)
			SumNodes(i, sum, 0);

		return sum;
	}
};
