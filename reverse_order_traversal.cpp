# include <iostream>
# include <vector>

using namespace std;

struct TreeNode {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

vector<vector<int>> zigzagLevelOrder(TreeNode* A) {
	vector<vector<int>> ret;

	if ( A == NULL) {
		return ret;
	}

	vector<TreeNode *> nodes = vector<TreeNode *>(1, A);
	int level = 0;
	while (!nodes.empty()) {
		vector<int> row;
		vector<TreeNode *> nextRow;
		for (const auto & n : nodes) {
			row.push_back(n->val);
			if (n->left != NULL) nextRow.push_back(n->left);
			if (n->right != NULL) nextRow.push_back(n->right);
		}
		if (level == 1|| level % 2 == 1) {
			// Need to reverse row
			vector<int> r_row;
			for (auto i = row.crbegin(); i != row.crend(); i++) {
				r_row.push_back(*i);
			}
			ret.push_back(r_row);
		} else {
			ret.push_back(row);
		}

		nodes = nextRow;
		level++;
	}
	return ret;
}

int main() {
	TreeNode * root = new TreeNode(1);
	TreeNode * two, * three, * four;
	two = root->left = new TreeNode(2);
	three = root->right = new TreeNode(3);
	four = two -> left = new TreeNode(4);
	two -> right = new TreeNode(5);
	three -> left = new TreeNode(6);
	three -> right = new TreeNode(7);
	four -> left = new TreeNode(8);
	four -> right = new TreeNode(9);
	vector<vector<int>> x = zigzagLevelOrder(root);
	for (const auto & r : x) {
		for (auto i : r) cout<<i<<" ";
		cout<<"\n";
	}
	return 0;
}
