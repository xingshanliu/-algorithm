// 解法1：先找到最小的结点，找他的后继，做累计
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
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        vector<pair<TreeNode*, int>> nodeList;
        TreeNode* minNode = root;
        while (minNode->left != nullptr) {
            minNode = minNode->left;
        }

        nodeList.push_back({minNode, minNode->val});
        preMin = nullptr;
        TreeNode* next = getNext(root, minNode->val);
        while (next != nullptr) {
            for (int i = 0; i < nodeList.size(); i++) {
                nodeList[i].second += next->val;
            }
            nodeList.push_back({next, next->val});
            preMin = nullptr;
            next = getNext(root, next->val);
        }

        for (int i = 0; i < nodeList.size(); i++) {
            nodeList[i].first->val = nodeList[i].second;
        }
        return root;
    }

    TreeNode* getNext(TreeNode* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val > val && (preMin == nullptr || preMin->val > root->val)) {
            preMin = root;
        }
        if (root->val == val) {
            if (root->right == nullptr) {
               return preMin;
            }

            TreeNode* cur = root->right;
            while (cur->left != nullptr) {
                cur = cur->left;
            }
            return cur;
        } else if (root->val > val) {
            return getNext(root->left, val);
        } else {
            return getNext(root->right, val);
        }
        return root;
    }

private:
    TreeNode* preMin;
};

// 解法二：反向中序遍历
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
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
        return root;
    }

private:
    int sum = 0;
};