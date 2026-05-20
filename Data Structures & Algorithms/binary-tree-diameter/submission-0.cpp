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
    int ans=0;
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        //count++;
        int l = dfs(root->left);
        int r = dfs(root->right);
        ans = max(ans,l+r);
        return 1+max( l,r);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        //if(root==NULL) return 0;
        //int ans = 0;
        //if(root->right!=NULL){ ans +=dfs(root->right,0); ans++;}
        //if(root->left!=NULL){ ans +=dfs(root->left,0); ans++;}
        dfs(root);
        return ans;
    }
};
