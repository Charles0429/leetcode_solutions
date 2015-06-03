#include <iostream>
#include <vector>

/**
 *
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * note:
 * the input is a 32-bit interger and should consider overflow
 */

class Solution 
{
public:
    int reverse(int x) 
    {
        int flag;
        std::vector<int> nums;
        long long r = 0;
        
        flag = x > 0 ? 1 : -1;
        x = std::abs(x);
        
        while(x)
        {
            nums.push_back(x%10);
            x /= 10;
        }
        
        for (const int &i : nums)
        {
            r = r * 10 + i;
        }
        
        r = r * flag;
        
        if (r > 2147483647 || r < -2147483648)
        {
            return 0;
        }
        else
        {
            return r;
        }
    }
};

int main(void)
{
    Solution test;
    std::cout << test.reverse(10000000) << std::endl;
    std::cout << test.reverse(2000000000) << std::endl;
    std::cout << test.reverse(2000000003) << std::endl;
    std::cout << test.reverse(-1000000) << std::endl;
    std::cout << test.reverse(-1999943453) << std::endl;
}
