/*
    You are given a 0-indexed integer array nums.

    Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. 
    If all such triplets have a negative value, return 0.

    The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].
*/

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long maxDiff=0,maxLeft=0,ans;
        for(int i=0;i<n;i++){
            ans=max(ans,(long long)maxDiff*nums[i]);
            maxLeft=max(maxLeft,(long long)nums[i]);
            maxDiff=max(maxDiff,(long long)maxLeft-nums[i]);
        }
        return ans;
    }
};