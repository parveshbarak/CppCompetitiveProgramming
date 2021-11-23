class Solution {
    public:
    vector<pair<TreeNode*,TreeNode*>> arr;
    TreeNode* prev = NULL;
    
    void solve(TreeNode* root) {
        if(root == NULL)  return;
        solve(root->left);
        if(prev && prev->val > root->val) arr.push_back({prev,root}); 
        prev = root;
        solve(root->right);
    }
    
    void recoverTree(TreeNode* root) {    
        solve(root);
        for(int i=0;i<)
        if(arr.size() == 1) 
            swap(arr[0].first->val, arr[0].second->val);
        // if(arr.size() == 2)
        //     swap(arr[0].first->val, arr[1].second->val);
    }
};