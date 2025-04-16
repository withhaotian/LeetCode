#include <iostream>
#include <vector> 

using namespace std;

class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
            vector<long long> dp(n);
    
            dp[n-1] = questions[n-1][0];
            for (int i = n-2; i >= 0; i --) {
                if (i+questions[i][1]+1 < n) {
                    dp[i] = max(dp[i+1], static_cast<long long>(questions[i][0]) + dp[i+questions[i][1]+1]);    
                }
                else {
                    dp[i] = max(dp[i+1], static_cast<long long>(questions[i][0]));
                }
            }
    
            return dp[0];
        }
    };

int main() {
    vector<vector<int>> questions = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{8,9},{9,10}};
    Solution sol;
    cout << sol.mostPoints(questions) << endl;
    return 0;
}