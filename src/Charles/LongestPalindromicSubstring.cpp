#include <iostream>

/**
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 *
 */

/**
 * solution:
 *
 *                 true i == j
 *                 true i == j-1 && s[i]==s[j]
 * dp[i][j] =      false i == j-1 && s[i]!=s[j]
 *                 true s[i] == s[j] && dp[i+1][j-1]==true
 *                 false s[i]!=s[j] || dp[i+1][j-1]==false
 *
 */ 
                
class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        bool dp[1001][1001] = {0};
        int i;
        int size = s.size();
        int start = 0;
        int end = 0;

        for (i = 0; i < size; i++)
        {
            dp[i][i] = true;
        }

        for (int l = 2; l <= size; l++)
        {
            for (int j = 0; j <= size - l; j++)
            {
                int k = j + l - 1;
                if (l == 2)
                {
                    dp[j][j+1] = (s[j] == s[j+1]) ? true : false;
                }
                else
                {
                    if (dp[j+1][k-1] && (s[j] == s[k]))
                    {
                        dp[j][k] = true;
                    }
                    else 
                    {
                        dp[j][k] = false;
                    }
                }
                if (dp[j][k] && (k-j) > (end-start))
                {
                    start = j;
                    end = k;
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};

int main(void)
{
    std::string s1("abccba");
    std::string s2("axbccbee");
    std::string s3("s");
    std::string s4("abccbaxxxabccbaxxxabcddcba");
    std::string s5("bb");

    Solution test;
    
    std::cout << test.longestPalindrome(s1) << std::endl;
    std::cout << test.longestPalindrome(s2) << std::endl;
    std::cout << test.longestPalindrome(s3) << std::endl;
    std::cout << test.longestPalindrome(s4) << std::endl;
    std::cout << test.longestPalindrome(s5) << std::endl;
}

