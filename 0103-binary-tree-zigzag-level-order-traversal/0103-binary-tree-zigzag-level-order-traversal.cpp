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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        deque<TreeNode*> dq;
        dq.push_back(root);

        int oddLevel = 1;
        while(!dq.empty()){
            int size = dq.size();
            vector<int> temp;
            for(int i = 0; i<size; i++){
                if(oddLevel){
                    TreeNode *node = dq.front();
                    dq.pop_front();
                    temp.push_back(node->val);
                    if(node->left)
                        dq.push_back(node->left);
                    if(node->right)
                        dq.push_back(node->right);
                }
                else{
                    TreeNode *node = dq.back();
                    dq.pop_back();
                    temp.push_back(node->val);
                    if(node->right)
                        dq.push_front(node->right);
                    if(node->left)
                        dq.push_front(node->left);
                }
            }
            oddLevel = !oddLevel;
            ans.push_back(temp);
        }
        return ans;
    }
};