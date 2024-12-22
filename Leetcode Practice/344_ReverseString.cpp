/*
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.
*/

//Basic Swapping
void reverseString(vector<char>& s) {
    int n=s.size();
    for(int i=0;i<n/2;i++){
        swap(s[i],s[n-i-1]);
    }
}
//Using Stack
void reverseString(vector<char>& s) {
    int n=s.size();
    stack<char>st;
    for(auto it:s){
        st.push(it);
    }
    for(int i=0;i<n;i++){
        s[i]=st.top();
        st.pop();
    }
}
//Using Inbuilt reverse() function in c++
void reverseString(vector<char>& s) {
    reverse(s.begin(),s.end());
}