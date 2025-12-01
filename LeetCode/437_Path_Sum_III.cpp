struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        return getSumCount(root, targetSum);
    }
    int getSumCount(TreeNode* root, int target){
        if(!root) return 0;
        int count = 0;
        int sum = 0;
        TreeNode* cur = root;
        while(cur){
            sum = sum + cur->val;
            if(sum == target) count++;
            cur = root->left;
        }
        sum = 0;
        cur = root;
        while(cur){
            sum += root->val;
            if(sum == target) count++;
            cur = root->right;
        }
        count += getSumCount(root->right, target);
        count += getSumCount(root->left, target);

        return count;
    }
    
};