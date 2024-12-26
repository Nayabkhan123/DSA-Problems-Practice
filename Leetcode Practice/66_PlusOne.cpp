/*
    You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the 
    integer. The digits are ordered from most significant to least significant in left-to-right order. 
    The large integer does not contain any leading 0's.
    Increment the large integer by one and return the resulting array of digits.
*/

//Beats 100.00%😊
vector<int> plusOne(vector<int>& digits) {
    int n=digits.size();
    for(int i=n-1;i>=0;i--){
        if(digits[i]<9){
            digits[i]++;
            return digits;
        }
        digits[i]=0;
    }
    digits[0]=1;
    digits.push_back(0);
    return digits;
}

vector<int> plusOne(vector<int>& digits) {
    int n=digits.size();
    if(digits[n-1]==9) {
        int i=1;
        while(n-i>=0){
            digits[n-i]=0;
            i++;
            if(n-i>=0&&digits[n-i]!=9){
                digits[n-i]++;
                break;
            }
        }
        if(i==n+1) {
            digits[0]=1;
            digits.push_back(0);
        }                
        return digits;
    }
    else{
        digits[n-1]++;
        return digits;
    }
}