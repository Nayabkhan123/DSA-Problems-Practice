/*
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.

    Example 1:

    Input: s = "anagram", t = "nagaram"

    Output: true

    Example 2:

    Input: s = "rat", t = "car"

    Output: false
*/

//Hash Table (Using Array)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int>freq(26);
        for(auto it : s){
            freq[it-'a']++;
        }
        for(auto it : t){
            if(freq[it-'a']==0) return false;
            freq[it-'a']--;
        }
        return true;
    }
};

//Hash Table

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int>mp;
        for(auto it : s){
            mp[it]++;
        }
        for(auto it : t){
            if(!mp[it]) return false;
            mp[it]--;
        }
        return true;
    }
};

//Sorting

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};