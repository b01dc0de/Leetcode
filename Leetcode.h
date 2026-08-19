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

namespace Leetcode_0013
{
    using std::string;

    class Solution
    {
    public:
        int romanToInt(string s);
    };

    void RunTest();
}

namespace Leetcode_0014
{
    using std::string;
    using std::vector;

    class Solution
    {
    public:
        string longestCommonPrefix(vector<string>& strs);
    };

    void RunTest();
}

namespace Leetcode_0020
{
    using std::string;

    class Solution
    {
    public:
        bool isValid(string s);
    };

    void RunTest();
}

namespace Leetcode_0021
{
    struct ListNode
    {
        int val;
        ListNode* next;

        ListNode() : val(0), next(nullptr)
        {
        }

        ListNode(int x) : val(x), next(nullptr)
        {
        }

        ListNode(int x, ListNode* next) : val(x), next(next)
        {
        }
    };

    class Solution
    {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
    };

    void RunTest();
}

namespace Leetcode_0026
{
    using std::vector;

    class Solution
    {
    public:
        int removeDuplicates(vector<int>& nums);
    };

    void RunTest();
}

namespace Leetcode_0058
{
    using std::string;

    class Solution
    {
    public:
        int lengthOfLastWord(string s);
    };

    void RunTest();
}

#endif // LEETCODE_H
