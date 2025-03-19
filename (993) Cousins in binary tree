/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void find(struct TreeNode* root, int val, int depth, struct TreeNode* parent, 
          int* foundDepth, struct TreeNode** foundParent) {
    if (!root) return;
    
    if (root->left && root->left->val == val) {
        *foundDepth = depth + 1;
        *foundParent = root;
        return;
    }
    
    if (root->right && root->right->val == val) {
        *foundDepth = depth + 1;
        *foundParent = root;
        return;
    }

    find(root->left, val, depth + 1, root, foundDepth, foundParent);
    find(root->right, val, depth + 1, root, foundDepth, foundParent);
}

bool isCousins(struct TreeNode* root, int x, int y) {
    int xDepth = -1, yDepth = -1;
    struct TreeNode* xParent = NULL;
    struct TreeNode* yParent = NULL;

    find(root, x, 0, NULL, &xDepth, &xParent);
    find(root, y, 0, NULL, &yDepth, &yParent);

    return (xDepth == yDepth) && (xParent != yParent);
}
