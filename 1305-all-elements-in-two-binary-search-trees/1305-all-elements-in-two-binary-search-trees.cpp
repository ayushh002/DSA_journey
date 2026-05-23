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
    void setQueue(TreeNode* root, queue<TreeNode*>& q){
        if(!root) return;

        setQueue(root->left, q);
        q.push(root);
        setQueue(root->right, q);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;

        queue<TreeNode*> q1, q2;
        setQueue(root1, q1);
        setQueue(root2, q2);

        while(!q1.empty() && !q2.empty()){
            TreeNode* top1 = q1.front();
            TreeNode* top2 = q2.front();

            if(top1->val==top2->val){
                ans.push_back(top1->val);
                ans.push_back(top2->val);
                q1.pop();
                q2.pop();
            }
            else if(top1->val<top2->val){
                ans.push_back(top1->val);
                q1.pop();
            }
            else{
                ans.push_back(top2->val);
                q2.pop();
            }
        }

        while(!q1.empty()){
            ans.push_back(q1.front()->val);
            q1.pop();
        }

        while(!q2.empty()){
            ans.push_back(q2.front()->val);
            q2.pop();
        }
        return ans;
    }
};