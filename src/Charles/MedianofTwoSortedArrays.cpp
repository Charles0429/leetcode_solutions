#include <iostream>
#include <vector>

/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n))
 *
 */

class Solution
{
public:
    double findMedianSortedArraysHelper(int *nums1, int m, int *nums2, int n, int k)
    {
        if (m > n)
        {
            return findMedianSortedArraysHelper(nums2, n, nums1, m, k);
        }
        
        if (m == 0)
        {
            return nums2[k-1];
        }

        if (k == 1)
        {
            return std::min(nums1[0], nums2[0]);
        }
        
        int index1 = std::min(k / 2, m);
        int index2 = k - index1;

        if (nums1[index1 - 1] == nums2[index2 - 1])
        {
            return nums1[index1 - 1];
        }
        else if (nums1[index1 - 1] > nums2[index2 - 1])
        {
            return findMedianSortedArraysHelper(nums1, m, nums2 + index2, n - index2, k - index2);
        }
        else
        {
            return findMedianSortedArraysHelper(nums1 + index1, m - index1, nums2, n, k - index1);
        }

    } 
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int *pnums1 = &nums1[0];
        int *pnums2 = &nums2[0];

        int k = (m + n) / 2;

        if ((m + n) % 2)
        {
            return findMedianSortedArraysHelper(pnums1, m, pnums2, n, k + 1);
        }
        else
        {
            double tmp1 = findMedianSortedArraysHelper(pnums1, m, pnums2, n, k);
            double tmp2 = findMedianSortedArraysHelper(pnums1, m, pnums2, n, k + 1);
            return 0.5 * (tmp1 + tmp2);
        }
    }
};

int main(void)
{
    //testcases

    //case1
    int nums1_array[] = {1, 2, 3, 4, 5}; //3

    //case2
    int nums4_array[] = {1, 2, 3, 4, 5}; //3

    //case3
    int nums5_array[] = {1, 2, 3}; // 2.5
    int nums6_array[] = {2, 3, 4};

    //case4
    int nums7_array[] = {1, 2, 3, 4}; //3
    int nums8_array[] = {2, 3, 4, 5};

    //case5
    int nums9_array[] = {100001};
    int nums10_array[] = {100000};

    Solution test;


    std::vector<int> num1(nums1_array, nums1_array + sizeof(nums1_array) / sizeof(int));
    std::vector<int> num2;
    std::cout << test.findMedianSortedArrays(num1, num2) << std::endl;;

    std::vector<int> num3;
    std::vector<int> num4(nums4_array, nums4_array + sizeof(nums4_array) / sizeof(int));
    std::cout << test.findMedianSortedArrays(num3, num4) << std::endl;
    
    std::vector<int> num5(nums5_array, nums5_array + sizeof(nums5_array) / sizeof(int));
    std::vector<int> num6(nums6_array, nums6_array + sizeof(nums6_array) / sizeof(int));
    std::cout << test.findMedianSortedArrays(num5, num6) << std::endl;;

    std::vector<int> num7(nums7_array, nums7_array + sizeof(nums7_array) / sizeof(int));
    std::vector<int> num8(nums8_array, nums8_array + sizeof(nums8_array) / sizeof(int));
    std::cout << test.findMedianSortedArrays(num7, num8) << std::endl;

    std::vector<int> num9(nums9_array, nums9_array + sizeof(nums9_array) / sizeof(int));
    std::vector<int> num10(nums10_array, nums10_array + sizeof(nums10_array) / sizeof(int));
    std::cout << test.findMedianSortedArrays(num9, num10) << std::endl;
}
