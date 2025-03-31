#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int percentageLetter(string s, char letter) {
            double n = s.size();
            double cnt = 0;
            for (auto ch : s) {
                if (ch == letter)   cnt ++;
            }
    
            return int((cnt / n) * 100);
        }
    };

int main() {
    string s = "vmvvvvvzrvvpvdvvvvyfvdvvvvpkvvbvvkvvfkvvvkvbvvnvvomvzvvvdvvvkvvvvvvvvvlvcvilaqvvhoevvlmvhvkvtgwfvvzy";
    char letter = 'v';
    Solution sol;

    cout << sol.percentageLetter(s, letter) << endl;

    return 0;
}