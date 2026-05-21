class Solution {
public:
    int returnNumericVal(char ch){
        if(ch >= '0' && ch <= '9'){
            return ch-'0';
        }
        if((char)tolower(ch)>='a'&&(char)tolower(ch)<='z'){
            return (char)tolower(ch)-'a';
        }
        return -1;
    }
    bool isPalindrome(string s) {
        int left = 0;
        int right=s.size()-1;

        while(left<=right){
            int leftVal = returnNumericVal(s[left]);
            int rightVal = returnNumericVal(s[right]);
            if(leftVal==-1){
                left++;
                continue;
            }
            if(rightVal==-1){
                right--;
                continue;
            }
            if(leftVal!=rightVal) return false;
            //cout<<s[left]<<" "<<s[right]<<endl;
            left++;
            right--;
        }
        return true;
    }
};
