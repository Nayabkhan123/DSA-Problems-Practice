/*
    Given an integer array nums, return true if any value appears at least twice in the array, 
    and return false if every element is distinct.
*/

//  Using set
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        return n!=s.size();
    }
};
// using hashmap
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]) return true;
            mp[nums[i]]++;
        }
        return false;
    }
};
// sorting
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) return true;
        }
        return false;
    }
};