/*
    Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.
*/

class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]>=65&&s[i]<=90){
                s[i]=s[i]+32;
            }
        } 
        return s;  
    }
};

string toLowerCase(string s) {
    for(int i=0;i<s.size();i++){
        s[i]=tolower(s[i]);
    } 
    return s;  
}