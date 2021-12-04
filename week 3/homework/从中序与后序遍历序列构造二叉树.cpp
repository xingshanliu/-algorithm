/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeDFS(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* buildTreeDFS(vector<int>& inorder, int l1, int r1, 
        vector<int>& postorder, int l2, int r2) {

        if (l1 > r1 || l2 > r2) {
            return nullptr;
        }

        TreeNode* root = new TreeNode;
        root->val = postorder[r2];
        int rootPos = l1;
        while (inorder[rootPos] != root->val) {
            rootPos++;
        }
        root->left = buildTreeDFS(inorder, l1, rootPos - 1, postorder, l2, l2 + rootPos - l1 - 1) ;
        root->right = buildTreeDFS(inorder, rootPos + 1, r1, postorder, l2 + rootPos - l1, r2 - 1); 
        return root;
    }
};