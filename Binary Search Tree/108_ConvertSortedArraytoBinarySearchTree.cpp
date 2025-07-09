/*
    Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced
    binary search tree.

    Example 1:
    Input: nums = [-10,-3,0,5,9]
    Output: [0,-3,9,-10,null,5]
    Explanation: [0,-10,5,null,-3,null,9] is also accepted:
*/

class Solution {
public:
    TreeNode* buildBST(vector<int>&nums,int start,int end){
        if(start>end) return NULL;
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(nums,start,mid-1);
        root->right = buildBST(nums,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return buildBST(nums,0,n-1);
    }
};