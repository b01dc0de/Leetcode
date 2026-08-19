#include "Leetcode.h"

namespace Leetcode_0001
{
    /*
        Leetcode_0001: Two Sum

        You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
        You may assume that each input would have exactly one solution, and you may not use the same element twice.
        You can return the answer in any order.

        Constraints:
            2 <= nums.length <= 10^4
            -10^9 <= nums[i] <= 10^9
            -10^9 <= target <= 10^9
            Only one valid answer exists.
    */
    using std::vector;

    vector<int> Solution::twoSum(vector<int>& nums, int target)
    {
        vector<int> Result;
        for (int FirstIdx = 0; FirstIdx < nums.size() - 1; FirstIdx++)
        {
            for (int SecondIdx = FirstIdx + 1; SecondIdx < nums.size(); SecondIdx++)
            {
                if (nums[FirstIdx] + nums[SecondIdx] == target)
                {
                    Result.push_back(FirstIdx);
                    Result.push_back(SecondIdx);
                    return Result;
                }
            }
        }
        return Result;
    }

    void RunTest()
    {
        Solution TestSolution;

        vector<int> Ex1_nums = {2, 7, 11, 15};
        int Ex1_target = 9;
        vector<int> Ex1_ExpectedResult = {0, 1};
        vector<int> Ex1_Output = TestSolution.twoSum(Ex1_nums, Ex1_target);

        vector<int> Ex2_nums = {3, 2, 4};
        int Ex2_target = 6;
        vector<int> Ex2_ExpectedResult = {1, 2};
        vector<int> Ex2_Output = TestSolution.twoSum(Ex2_nums, Ex2_target);

        vector<int> Ex3_nums = {3, 3};
        int Ex3_target = 6;
        vector<int> Ex3_ExpectedResult = {0, 1};
        vector<int> Ex3_Output = TestSolution.twoSum(Ex3_nums, Ex3_target);

        return;
    }
}
