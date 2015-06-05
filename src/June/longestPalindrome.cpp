class Solution {
public:
    string longestPalindrome(string s) {
        int longestLen = 0;
        int longestIndex = 0;
    
        for(int currentIndex = 0; currentIndex < s.length(); currentIndex++) {
            if(isPalindrome(s,currentIndex - longestLen, currentIndex)){
                longestLen += 1;
                longestIndex = currentIndex;
            } else if(currentIndex - longestLen - 1 >= 0 && 
                      isPalindrome(s, currentIndex - longestLen - 1, currentIndex)) {
                longestLen += 2;
                longestIndex = currentIndex;
            }   
        }
        longestIndex++;
        
        return s.substr(longestIndex - longestLen, longestLen);
    }
    bool isPalindrome(string s, int startIndex, int endIndex) {
    for(int i = startIndex, j = endIndex; i <= j; i++, j--) 
            if (s[i] != s[j] )  return false;
    return true;
}
};
