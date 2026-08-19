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

namespace Leetcode_0009
{
    /*
        Leetcode_0009: Palindrome Number

        Given an integer x, return true if x is a , and false otherwise.

        Constraints:
            -2^31 <= x <= 2^31 - 1
    */

    bool Solution::isPalindrome(int x)
    {
        if (x < 0) { return false; }

        std::vector<char> AsString;

        while (x > 0)
        {
            int Remainder = x % 10;
            char RemainderAsChar = Remainder + 0x30;
            AsString.push_back(Remainder);
            x /= 10;
        }

        for (int Idx = 0; Idx < AsString.size() / 2; Idx++)
        {
            if (AsString[Idx] != AsString[AsString.size() - Idx - 1])
            {
                return false;
            }
        }
        return true;
    }

    void RunTest()
    {
        Solution TestSolution;

        int Ex1_x = 121;
        bool Ex1_ExpectedResult = true;
        bool Ex1_Output = TestSolution.isPalindrome(Ex1_x);

        int Ex2_x = -121;
        bool Ex2_ExpectedResult = false;
        bool Ex2_Output = TestSolution.isPalindrome(Ex2_x);

        int Ex3_x = 10;
        bool Ex3_ExpectedResult = false;
        bool Ex3_Output = TestSolution.isPalindrome(Ex2_x);

        return;
    }
}

namespace Leetcode_0014
{
    /*
        Leetcode_0014: Longest Common Prefix

        Write a function to find the longest common prefix string amongst an array of strings.
        If there is no common prefix, return an empty string "".

        Constraints:
            1 <= strs.length <= 200
            0 <= strs[i].length <= 200
            strs[i] consists of only lowercase English letters if it is non-empty.
    */
    using std::string;
    using std::vector;

    string Solution::longestCommonPrefix(vector<string>& strs)
    {
        int PrefixLength = 0;

        bool bFinished = false;
        while (!bFinished && strs[0].length() > PrefixLength)
        {
            char NextChar = strs[0][PrefixLength];
            for (int StrsIdx = 1; StrsIdx < strs.size(); StrsIdx++)
            {
                if (strs[StrsIdx].length() <= PrefixLength || strs[StrsIdx][PrefixLength] != NextChar)
                {
                    bFinished = true;
                    break;
                }
            }

            if (!bFinished) { PrefixLength++; }
        }

        string Result = strs[0].substr(0, PrefixLength);
        return Result;
    }

    void RunTest()
    {
        Solution TestSolution;

        vector<string> Ex1_strs = {"flower", "flow", "flight"};
        string Ex1_ExpectedResult = "fl";
        string Ex1_Output = TestSolution.longestCommonPrefix(Ex1_strs);

        vector<string> Ex2_strs = {"dog", "racecar", "car"};
        string Ex2_ExpectedResult = "";
        string Ex2_Output = TestSolution.longestCommonPrefix(Ex2_strs);

        return;
    }
}
