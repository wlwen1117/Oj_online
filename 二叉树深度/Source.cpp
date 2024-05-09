#include <iostream>
#include <queue>

using namespace std;
 struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:

    int run(TreeNode* root) {
        return getDepth(root);
    }

    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);

        if (node->left == NULL && node->right != NULL) {
            return 1 + rightDepth;
        }

        if (node->left != NULL && node->right == NULL) {
            return 1 + leftDepth;
        }

        int result = 1 + min(leftDepth, rightDepth);
        return result;
    }
};


int main(void) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    int minDep = sol.run(root);
    cout << "最小深度： " << minDep << endl;


    return 0;
}