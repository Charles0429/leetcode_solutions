#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class Solution 
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> hash;
        std::vector<int> r;
        int i;
        int size = nums.size();

        for(i = 0; i < size; i++)
        {
            hash.insert(std::make_pair(nums[i], i+1));
        }

        for(i = 0; i < size; i++)
        {
            std::unordered_map<int, int>::iterator iter = hash.find(target - nums[i]);
            
            if (iter != hash.end())
            {
                if (iter->second != (i + 1)) 
                {
                    r.push_back(iter->second < (i + 1) ? iter->second : i + 1);
                    r.push_back(iter->second > (i + 1) ? iter->second : i + 1);
                    return r;
                } 
            }
        }
        return r;
    }    
};


int main(void)
{
    //test cases
    int nums_array1[] = {2, 7, 11, 15};
    int target1 = 9;
    int nums_array2[] = {2, 3};
    int target2 = 4;
    int nums_array3[] = {2, 5, 7, 9};
    int target3 = 6;

    std::vector<int> nums1(nums_array1, nums_array1 + sizeof(nums_array1) / sizeof(int));
    Solution test;
    std::vector <int> r;
    
    r = test.twoSum(nums1, target1);
    

    for (int i = 0; i < r.size(); i++)
    {
        std::cout << r[i] << std::endl;
    }

    std::vector<int> nums2(nums_array2, nums_array2 + sizeof(nums_array2) / sizeof(int));
    r = test.twoSum(nums2, target2);
 
    for (int i = 0; i < r.size(); i++)
    {
        std::cout << r[i] << std::endl;
    }
    
    std::vector<int> nums3(nums_array3, nums_array3 + sizeof(nums_array3) / sizeof(int));
    r = test.twoSum(nums3, target3);
 
    for (int i = 0; i < r.size(); i++)
    {
        std::cout << r[i] << std::endl;
    }
}
