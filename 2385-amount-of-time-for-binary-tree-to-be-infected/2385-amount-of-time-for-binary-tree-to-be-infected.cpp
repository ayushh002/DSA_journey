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
    int getInfected(TreeNode* root, int& upward_total_time, int start){
        if(!root) return 0;

        if(root->val==start)
            return -1;
        
        int left = getInfected(root->left, upward_total_time, start);
        int right = getInfected(root->right, upward_total_time, start);

        if(left<0){
            upward_total_time = max(upward_total_time, abs(left)+right);
            return left-1;
        }
        if(right<0){
            upward_total_time = max(upward_total_time, left+abs(right));
            return right-1;
        }

        return 1+max(left, right);
    }

    void findTarget(TreeNode* root, TreeNode*& infected, int start){
        if(!root) return;

        if(root->val==start){
            infected = root;
            return;
        }

        findTarget(root->left, infected, start);
        findTarget(root->right, infected, start);
    }

    int getHeight(TreeNode* infected){
        if(!infected) return 0;
        return 1+max(getHeight(infected->left), getHeight(infected->right));
    }

    int amountOfTime(TreeNode* root, int start) {
        // Part 1: Get the time for upward + other branches
        int total_upward_time = 0;
        getInfected(root, total_upward_time, start);

        // Part 2: Get the time for downward subtrees
        // A) First - get the address of the starting node
        TreeNode* infected = NULL;
        findTarget(root, infected, start);

        // B. Second - get the downward height(time)
        int height = getHeight(infected)-1;

        // Return the max of upward and downward time
        return max(total_upward_time, height);
    }
};