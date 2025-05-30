/*
给你两个字符串 word1 和 word2 。请你从 word1 开始，通过交替添加字母来合并字符串。如果一个字符串比另一个字符串长，就将多出来的字母追加到合并后字符串的末尾。

返回 合并后的字符串 。

 

示例 1：

输入：word1 = "abc", word2 = "pqr"
输出："apbqcr"
解释：字符串合并情况如下所示：
word1：  a   b   c
word2：    p   q   r
合并后：  a p b q c r
示例 2：

输入：word1 = "ab", word2 = "pqrs"
输出："apbqrs"
解释：注意，word2 比 word1 长，"rs" 需要追加到合并后字符串的末尾。
word1：  a   b 
word2：    p   q   r   s
合并后：  a p b q   r   s
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = 0;
        int l2 = 0;
        string res = "";
        while (l1 < word1.size() && l2 < word2.size()) {
            res += word1[l1++];
            res += word2[l2++];
        }

        while (l1 < word1.size()) {
            res += word1[l1++];
        }

        while (l2 < word2.size()) {
            res += word2[l2++];
        }

        return res;
    }
};

int main() {
    Solution s;
    string word1 = "abcd";
    string word2 = "pq";

    cout << s.mergeAlternately(word1, word2) << endl;

    return 0;
}