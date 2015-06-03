#include <iostream>

/**
 * Determine whether an integer is a palindrome. Do this without extra space.
 */

/**
 * Question: I have not considered overlflow, but is still accepted by leetcode?
 */

class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        int r = 0;
        int t = x;
        
        if (x < 0)
        {
            return false;
        }
        
        while (t)
        {
            r = r * 10 + t % 10;
            t /= 10;
        }
        
        return r == x;
    }
};

int main(void)
{
    Solution test;

    std::cout << test.isPalindrome(2000000003) << std::endl;
}
