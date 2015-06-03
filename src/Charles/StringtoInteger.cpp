#include <iostream>
#include <string>
#include <climits>

/**
 *
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 *
 */

/**
 * Solution:
 * 1. skip leading spaces
 * 2. consider positive or negative symbol
 * 3. stop converting when encountering a invalid character
 * 4. consider overflow
 */

class Solution 
{
public:
    int myAtoi(std::string str) 
    {
        int r = 0;
        int flag = 1;
        int index = 0;
        
        while (index < str.size() && str[index] == ' ')
        {
            index++;
        }
        
        if (str[index] == '+' || str[index] == '-')
        {
            if (str[index] == '-')
            {
                flag = -1;
            }
            index++;
        }
        
        while (index < str.size())
        {
            if (str[index] < '0' || str[index] > '9')
            {
                break;
            }
         
            int val = str[index] - '0';   
            if (r > INT_MAX / 10 || (r == INT_MAX / 10 && val > INT_MAX % 10))
            {
                r = flag == 1 ? INT_MAX : INT_MIN;
                return r;
            }
            
            r = r * 10 + val;
            index++;
        }
        
        return r * flag;
    }
};

int main(void)
{
    Solution test;

    std::cout << test.myAtoi("-2147483648") << std::endl;
    std::cout << test.myAtoi("2147483647") << std::endl;
    std::cout << test.myAtoi("2147483648") << std::endl;
    std::cout << test.myAtoi("-1000000") << std::endl;
    std::cout << test.myAtoi("-2147483649") << std::endl;
}
