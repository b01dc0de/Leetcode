#ifndef LEETCODE_H
#define LEETCODE_H

#include <string>
#include <vector>

namespace Leetcode_0001
{
    using std::vector;

    class Solution
    {
    public:
        vector<int> twoSum(vector<int>& nums, int target);
    };

    void RunTest();
}

namespace Leetcode_0009
{
    class Solution
    {
    public:
        bool isPalindrome(int x);
    };

    void RunTest();
}

namespace Leetcode_0014
{
    using std::string;
    using std::vector;

    class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs);
    };

    void RunTest();
}

#endif // LEETCODE_H
