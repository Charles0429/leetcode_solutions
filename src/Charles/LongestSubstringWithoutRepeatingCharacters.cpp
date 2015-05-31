#include <iostream>
#include <unordered_map>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int i;
        int start = 0;
        int max_length = 0;
        std::unordered_map<char, int> t;

        for (i = 0; i < s.size(); i++)
        {
            std::unordered_map<char, int>::iterator iter = t.find(s[i]);

            if (iter == t.end())
            {
                t.insert(std::make_pair(s[i], i));
            }
            else
            {
                start = std::max(start, iter->second + 1);
                t[s[i]] = i;
            }

            max_length = std::max(max_length, i - start + 1);
        }

        return max_length;
    }
};

int main(void)
{
    //testcases
    std::string s1("abcdef");  //6
    std::string s2("abcabcabc"); //3
    std::string s3("bbbbb"); //1
    std::string s4("abcabcdabcde"); //5
    std::string s5("dvdf"); //3
    std::string s6("opnaewkpdyovkhizgjg"); //11

    Solution test;

    std::cout << test.lengthOfLongestSubstring(s1) << std::endl;
    std::cout << test.lengthOfLongestSubstring(s2) << std::endl;
    std::cout << test.lengthOfLongestSubstring(s3) << std::endl;
    std::cout << test.lengthOfLongestSubstring(s4) << std::endl;
    std::cout << test.lengthOfLongestSubstring(s5) << std::endl;
    std::cout << test.lengthOfLongestSubstring(s6) << std::endl;
}
