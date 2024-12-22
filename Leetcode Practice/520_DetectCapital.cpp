/*
We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.
*/

bool detectCapitalUse(string word) {
    int n=word.length();
    int cnt=0;
    for(int i=0;i<n;i++){
        if(word[i]>=65&&word[i]<=90){
            cnt++;
        }
    }
    if(cnt==0) return true;
    if(cnt==n) return true;
    if(cnt==1&&word[0]>=65&&word[0]<=90) return true;
    return false;
}


bool detectCapitalUse(string word) {
    int n=word.size();
    if(word[0]>='a'&&word[0]<='z'){
        for(auto it:word){
            if(it<'a'||it>'z'){
                return false;
            }
        }
    }
    else if(word[0]>='A'&&word[0]<='Z'){
        if(word.size()>1){
            if(word[1]>='a'&&word[1]<='z'){
                for(int i=1;i<n;i++){
                    if(word[i]<'a'||word[i]>'z'){
                        return false;
                    }
                }
            }
            else if(word[1]>='A'&&word[1]<='Z'){
                for(int i=1;i<n;i++){
                    if(word[i]<'A'||word[i]>'Z'){
                    return false;
                    }
                }
            }   
        }
    }
    return true;
}