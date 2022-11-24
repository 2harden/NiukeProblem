/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 计算机也是以整数的形式存储char的，取值范围0-255
        // 这个dirc你可以理解成一个字典，key是char的数值，value是它在s中的当前位置
        vector<int> dirc(256, -1);
        // maxLen顾名思义，就是用来存储最终结果的
        // start就是用来存储子串的起始点的
        int maxLength = 0;
        int start = -1;
        for (int i = 0; i < s.length(); i++)
        {
            // dict[s[i]] > start 代表这个char在之前已经出现过了
            // 这时需要更新起始点的位置
            // cout << "dirc[s[i]] = " << dirc[s[i]] << '\t'; // output: dirc[s[i]] = -1 dirc[s[i]] = -1 dirc[s[i]] = -1 dirc[s[i]] = 0  dirc[s[i]] = 1  dirc[s[i]] = 2  dirc[s[i]] = 4  dirc[s[i]] = 6
            // int a = s[i];
            // cout << "a = " << a << '\t'; // output: a = 97  a = 98  a = 99  a = 97  a = 98  a = 99  a = 98  a = 98
            if (dirc[s[i]] > start)
            {
                start = dirc[s[i]];
            }
            // 保存当前字符的位置
            dirc[s[i]] = i;
            maxLength = max(maxLength, i - start);
        }

        return maxLength;
    }
};
// @lc code=end
int main()
{
    Solution s;
    string str = "abcabcbb";
    s.lengthOfLongestSubstring(str);

    return 0;
}

