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
    using std::vector;

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

namespace Leetcode_0013
{
    /*
        Leetcode_0013: Roman to Integer

        Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
        Symbol       Value
            I             1
            V             5
            X             10
            L             50
            C             100
            D             500
            M             1000
        For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
        Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
            I can be placed before V (5) and X (10) to make 4 and 9.
            X can be placed before L (50) and C (100) to make 40 and 90.
            C can be placed before D (500) and M (1000) to make 400 and 900.
        Given a roman numeral, convert it to an integer.

        Constraints:
            1 <= s.length <= 15
            s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
            It is guaranteed that s is a valid roman numeral in the range [1, 3999].
    */

    int Solution::romanToInt(string s)
    {
        auto GetSymbolValue = [](char Symbol) -> int
        {
            switch (Symbol)
            {
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
            }
            return 0;
        };

        int Sum = 0;

        for (int Idx = s.length() - 1; Idx >= 0; Idx--)
        {
            if (Idx < s.length() - 1)
            {
                char After = s[Idx + 1];
                switch (s[Idx])
                {
                    case 'I': { if (After == 'V' || After == 'X') { Sum -= 1; continue; } } break;
                    case 'X': { if (After == 'L' || After == 'C') { Sum -= 10; continue; } } break;
                    case 'C': { if (After == 'D' || After == 'M') { Sum -= 100; continue; } } break;
                }
            }
            Sum += GetSymbolValue(s[Idx]);
        }

        return Sum;
    }

    void RunTest()
    {
        Solution TestSolution;

        string Ex1_s = "III";
        int Ex1_ExpectedResult = 3;
        int Ex1_Output = TestSolution.romanToInt(Ex1_s);

        string Ex2_s = "LVIII";
        int Ex2_ExpectedResult = 58;
        int Ex2_Output = TestSolution.romanToInt(Ex2_s);

        string Ex3_s = "MCMXCIV";
        int Ex3_ExpectedResult = 1994;
        int Ex3_Output = TestSolution.romanToInt(Ex3_s);

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

namespace Leetcode_0020
{
    /*
        Leetcode_0020: Valid Parentheses

        Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

        An input string is valid if:
            Open brackets must be closed by the same type of brackets.
            Open brackets must be closed in the correct order.
            Every close bracket has a corresponding open bracket of the same type.

        Constraints:
            1 <= s.length <= 104
            s consists of parentheses only '()[]{}'.
    */
    using std::vector;

    bool Solution::isValid(string s)
    {
        vector<char> BracketStack;
        bool bValid = true;

        for (int Idx = 0; bValid && Idx < s.length(); Idx++)
        {
            switch (s[Idx])
            {
                case '(':
                case '[':
                case '{':
                {
                    BracketStack.push_back(s[Idx]);
                } break;

                case ')':
                {
                    if (!BracketStack.empty() && BracketStack.back() == '(') { BracketStack.pop_back(); }
                    else { bValid = false; }
                } break;
                case ']':
                {
                    if (!BracketStack.empty() && BracketStack.back() == '[') { BracketStack.pop_back(); }
                    else { bValid = false; }
                } break;
                case '}':
                {
                    if (!BracketStack.empty() && BracketStack.back() == '{') { BracketStack.pop_back(); }
                    else { bValid = false; }
                } break;
            }
        }

        return bValid && BracketStack.empty();
    }

    void RunTest()
    {
        Solution TestSolution;

        string Ex1_s = "()";
        bool Ex1_ExpectedResult = true;
        bool Ex1_Output = TestSolution.isValid(Ex1_s);

        string Ex2_s = "()[]{}";
        bool Ex2_ExpectedResult = true;
        bool Ex2_Output = TestSolution.isValid(Ex2_s);

        string Ex3_s = "(]";
        bool Ex3_ExpectedResult = false;
        bool Ex3_Output = TestSolution.isValid(Ex3_s);

        string Ex4_s = "([])";
        bool Ex4_ExpectedResult = true;
        bool Ex4_Output = TestSolution.isValid(Ex4_s);

        string Ex5_s = "([)]";
        bool Ex5_ExpectedResult = false;
        bool Ex5_Output = TestSolution.isValid(Ex5_s);

        return;
    }
}

namespace Leetcode_0021
{
    /*
        Leetcode_0021: Merge Two Sorted Lists

        You are given the heads of two sorted linked lists list1 and list2.
        Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
        Return the head of the merged linked list.

        Constraints:
            The number of nodes in both lists is in the range [0, 50].
            -100 <= Node.val <= 100
            Both list1 and list2 are sorted in non-decreasing order.
    */
    using std::string;

    ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (!list1 && !list2) { return nullptr; }
        else if (list1 && !list2) { return list1; }
        else if (!list1 && list2) { return list2; }

        ListNode* Result = nullptr;
        ListNode* CurrNode = nullptr;
        if (list1->val < list2->val)
        {
            CurrNode = list1;
            list1 = list1->next;
        }
        else
        {
            CurrNode = list2;
            list2 = list2->next;
        }
        Result = CurrNode;

        while (list1 || list2)
        {
            if (list1 && !list2)
            {
                CurrNode->next = list1;
                CurrNode = list1;
                list1 = list1->next;
            }
            else if (!list1 && list2)
            {
                CurrNode->next = list2;
                CurrNode = list2;
                list2 = list2->next;
            }
            else
            {
                if (list1->val < list2->val)
                {
                    CurrNode->next = list1;
                    CurrNode = list1;
                    list1 = list1->next;
                }
                else
                {
                    CurrNode->next = list2;
                    CurrNode = list2;
                    list2 = list2->next;
                }
            }
        }

        return Result;
    }

    string ListNodeToSring(ListNode* list)
    {
        string Result;
        Result += '[';
        while (list)
        {
            Result += (char)(list->val + 0x30);
            list = list->next;
            if (list) { Result += ','; }
        }
        Result += ']';

        return Result;
    }

    void RunTest()
    {
        Solution TestSolution;

        ListNode Ex1_list1_2{4, nullptr};
        ListNode Ex1_list1_1{2, &Ex1_list1_2};
        ListNode Ex1_list1_0{1, &Ex1_list1_1};
        ListNode Ex1_list2_2{4, nullptr};
        ListNode Ex1_list2_1{3, &Ex1_list2_2};
        ListNode Ex1_list2_0{1, &Ex1_list2_1};
        string Ex1_ExpectedResult = "[1,1,2,3,4,4]";
        ListNode* Ex1_ResultNode = TestSolution.mergeTwoLists(&Ex1_list1_0, &Ex1_list2_0);
        string Ex1_Output = ListNodeToSring(Ex1_ResultNode);



        ListNode* Ex2_list1 = nullptr;
        ListNode* Ex2_list2 = nullptr;
        string Ex2_ExpectedResult = "[]";
        ListNode* Ex2_ResultNode = TestSolution.mergeTwoLists(Ex2_list1, Ex2_list2);
        string Ex2_Output = ListNodeToSring(Ex2_ResultNode);



        ListNode *Ex3_list1 = nullptr;
        ListNode Ex3_list2_0{0, nullptr};
        string Ex3_ExpectedResult = "[0]";
        ListNode* Ex3_ResultNode = TestSolution.mergeTwoLists(Ex3_list1, &Ex3_list2_0);
        string Ex3_Output = ListNodeToSring(Ex3_ResultNode);

        return;
    }
}

namespace Leetcode_0026
{
    /*
        Leetcode_0026: Remove Duplicates from Sorted Array

        Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
        Consider the number of unique elements in nums to be k. After removing duplicates, return the number of unique elements k.
        The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

        Custom Judge:
            The judge will test your solution with the following code:

            int[] nums = [...]; // Input array
            int[] expectedNums = [...]; // The expected answer with correct length

            int k = removeDuplicates(nums); // Calls your implementation

            assert k == expectedNums.length;
            for (int i = 0; i < k; i++) {
                assert nums[i] == expectedNums[i];
            }
        If all assertions pass, then your solution will be accepted.

        Constraints:
            1 <= nums.length <= 3 * 10^4
            -100 <= nums[i] <= 100
            nums is sorted in non-decreasing order.
    */

    int Solution::removeDuplicates(vector<int>& nums)
    {
        int NumDuplicates = 0;
        for (int Idx = nums.size() - 1; Idx >= 1;)
        {
            while (Idx >= 1 && nums[Idx] == nums[Idx - 1])
            {
                vector<int>::const_iterator ToRemove = nums.cbegin() + Idx;
                nums.erase(ToRemove);
                Idx--;
            }
            Idx--;
        }
        return nums.size();
    }

    void RunTest()
    {
        Solution TestSolution;

        vector<int> Ex1_nums = {1, 1, 2};
        int Ex1_ExpectedResult = 2;
        vector<int> Ex1_Expected_nums = {1, 2};
        int Ex1_Output = TestSolution.removeDuplicates(Ex1_nums);

        vector<int> Ex2_nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int Ex2_ExpectedResult = 5;
        vector<int> Ex2_Expected_nums = {0, 1, 2, 3, 4};
        int Ex2_Output = TestSolution.removeDuplicates(Ex2_nums);

        return;
    }
}

namespace Leetcode_0027
{
    /*
        Leetcode_0027: Remove Element

        Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
        Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
        Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
        Return k.

        Constraints:
            0 <= nums.length <= 100
            0 <= nums[i] <= 50
            0 <= val <= 100
    */

    int Solution::removeElement(vector<int> &nums, int val)
    {
        for (int Idx = nums.size() - 1; Idx >= 0; Idx--)
        {
            if (nums[Idx] == val)
            {
                vector<int>::const_iterator ToRemove = nums.begin() + Idx;
                nums.erase(ToRemove);
            }
        }
        return nums.size();
    }

    void RunTest()
    {
        Solution TestSolution;

        vector<int> Ex1_nums = {3, 2, 2, 3};
        int Ex1_val = 3;
        vector<int> Ex1_Expected_nums = {2, 2};
        int Ex1_ExpectedResult = 2;
        int Ex1_Output = TestSolution.removeElement(Ex1_nums, Ex1_val);

        vector<int> Ex2_nums = {0, 1, 2, 2, 3, 0, 4, 2};
        int Ex2_val = 2;
        vector<int> Ex2_Expected_nums = {0, 1, 3, 0, 4};
        int Ex2_ExpectedResult = 5;
        int Ex2_Output = TestSolution.removeElement(Ex2_nums, Ex2_val);

        return;
    }
}

namespace Leetcode_0058
{
    /*
        Leetcode_0058: Length of Last Word

        Given a string s consisting of words and spaces, return the length of the last word in the string.
        A word is a maximal consisting of non-space characters only.

        Constraints:
            1 <= s.length <= 104
            s consists of only English letters and spaces ' '.
            There will be at least one word in s.
    */

    int Solution::lengthOfLastWord(string s)
    {
        if (s.length() == 0) { return 0; }

        int Idx = s.length() - 1;
        while (Idx >= 0 && s[Idx] == ' ') { Idx--; }

        int LastWordEndIdx = -1;
        if (Idx >= 0 && s[Idx] != ' ') { LastWordEndIdx = Idx; }

        while (Idx > 0 && s[Idx] != ' ') { Idx--; }
        if (s[Idx] == ' ') { return LastWordEndIdx - Idx; }
        else { return LastWordEndIdx - Idx + 1; }
    }

    void RunTest()
    {
        Solution TestSolution;

        string Ex1_s = "Hello World";
        int Ex1_ExpectedResult = 5;
        int Ex1_Output = TestSolution.lengthOfLastWord(Ex1_s);

        string Ex2_s = "   fly me   to   the moon  ";
        int Ex2_ExpectedResult = 4;
        int Ex2_Output = TestSolution.lengthOfLastWord(Ex2_s);

        string Ex3_s = "luffy is still joyboy";
        int Ex3_ExpectedResult = 6;
        int Ex3_Output = TestSolution.lengthOfLastWord(Ex3_s);

        return;
    }
}
