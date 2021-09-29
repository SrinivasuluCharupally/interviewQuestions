struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


stack<TreeNode*> path;
void pushall(TreeNode* root)
{
    while (root)
    {
        path.push(root);
        root = root->left;
    }
}

BSTIterator::BSTIterator(TreeNode *root) {
    pushall(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !path.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* tmp = path.top();
    path.pop();
    pushall(tmp->right);
    return tmp->val;
}
