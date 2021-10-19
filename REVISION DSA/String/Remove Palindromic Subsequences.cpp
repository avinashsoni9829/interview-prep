class Solution {
public:
    bool isPalindrome(string s){
        string temp = s;
        reverse(temp.begin(),temp.end());
        return (s == temp);
    }
    int removePalindromeSub(string s) {
        
        if(isPalindrome(s)){
            return 1;
        }
        
        return 2;
        
    }
};
