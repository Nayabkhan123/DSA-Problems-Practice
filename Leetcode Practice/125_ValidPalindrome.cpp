/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all 
non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters 
and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/


bool isPalindrome(string s) {
    int start=0,end=s.length()-1;
    while(start<end){
        if(!isalnum(s[start])) start++;
        else if(!isalnum(s[end])) end--;
        else if(tolower(s[start])!=tolower(s[end])){
            return false;
        }
        else{
            start++;
            end--;
        }    
    }
    return true;
}

bool isPalindrome(string s) {
    string ans="";
    bool flag=true;
    for(auto it:s){
        if(it>=97&&it<=122||it>=65&&it<=90||it>=48&&it<=57){
            if(it>=65&&it<=90){
                ans+=it+32;
            }
            else
            ans+=it;
        }
    }
    for(int i=0;i<ans.size()/2;i++){
        if(ans[i]!=ans[ans.size()-i-1]){
            flag=false;
            break;
        }
    }
    return flag;
}