class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int cp = preorder.size();
        int ci = inorder.size();
        
        if(cp <= 0 or ci <= 0 or cp != ci) {
            return nullptr;
        }
        
        int index = 0;
        
        return treeSketch(preorder, inorder, 0, preorder.size() - 1, index );
    }
    
    TreeNode* treeSketch(vector<int>& preorder, vector<int>& inorder, int left, int right, int &index) 
    {
        if(left > right) {
            return nullptr;
        }
        
        TreeNode* root =new TreeNode( preorder[index++]);

        int p = -1;

        for(int i = 0; i < inorder.size(); i++) {
            if(inorder[i] == root->val) {
                p = i;
            }
        }        
        
        root->left = treeSketch(preorder, inorder, left, p - 1, index);
        root->right = treeSketch(preorder, inorder, p+1, right, index);
        
        return root;
    }
};