/*
对于字符串 s 和 t，只有在 s = t + t + t + ... + t + t（t 自身连接 1 次或多次）时，我们才认定 “t 能除尽 s”。

给定两个字符串 str1 和 str2 。返回 最长字符串 x，要求满足 x 能除尽 str1 且 x 能除尽 str2 。

示例 1：

输入：str1 = "ABCABC", str2 = "ABC"
输出："ABC"
示例 2：

输入：str1 = "ABABAB", str2 = "ABAB"
输出："AB"
示例 3：

输入：str1 = "LEET", str2 = "CODE"
输出：""
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    bool check(string x, string s) {
        int len = s.length() / x.length();
        string res = "";
        for (int i = 0; i < len; i++) {
            res = res + x;
        }
        
        return res == s;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        
        for (int i = min(len1, len2); i >= 1; i--) {
            if (len1 % i == 0 && len2 % i == 0) {
                string x = str1.substr(0, i);
                if (check(x, str1) && check(x, str2)) {
                    return x;
                }
            }
        }

        return "";
    }
};

int main() {
    Solution solution;
    string str1 = "LEET";
    string str2 = "CODE";
    cout << solution.gcdOfStrings(str1, str2) << endl;
    return 0;
}