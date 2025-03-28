#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        int minimizedStringLength(string s) {
            return unordered_set<char>(s.begin(), s.end()).size();
        }
    };

int main() {
    string s = "abcabcbb";
    Solution solution;
    cout << solution.minimizedStringLength(s) << endl;
    return 0;
}