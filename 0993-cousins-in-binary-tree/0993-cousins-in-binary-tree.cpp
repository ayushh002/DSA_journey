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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            TreeNode *leftParent = NULL, *rightParent = NULL;
            for(int i = 0; i<size; i++){
                TreeNode* element = q.front();
                q.pop();

                if(element->left){
                    if(element->left->val==x)
                        leftParent = element;
                    if(element->left->val==y)
                        rightParent = element;
                    q.push(element->left);
                }
                if(element->right){
                    if(element->right->val==x)
                        leftParent = element;
                    if(element->right->val==y)
                        rightParent = element;
                    q.push(element->right);
                }
            }

            if(leftParent && rightParent && leftParent!=rightParent)
                return true;
        }
        return false;
    }
};