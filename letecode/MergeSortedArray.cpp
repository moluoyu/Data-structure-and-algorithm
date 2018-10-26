/**
 * @brief 
 * 
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array. Note: You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 * 
 * @file MergeSortedArray.cpp
 * @author Luo Yu
 * @date 2018-09-14
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> nums;
        int i = 0, j = 0;
        while (i < m || j < n)
        {
            if (i < m && j < n)
            {
                if (nums1[i] < nums2[j])
                {
                    nums.push_back(nums1[i]);
                    i++;
                }
                else
                {
                    nums.push_back(nums2[j]);
                    j++;
                }
            }
            else if (i < m)
            {
                nums.push_back(nums1[i]);
                i++;
            }
            else if (j < n)
            {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        nums1 = nums;
    }
}