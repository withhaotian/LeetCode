class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int, int> cnt;
    
            int res = 0;
            for (int i = 0; i < answers.size(); i++) {
                if (answers[i] == 0) {
                    res ++;
                    continue;
                }
                cnt[answers[i]]++;
                if (cnt[answers[i]] == 1) {
                    res += answers[i] + 1;
                }
                else if (cnt[answers[i]] > answers[i] + 1) {
                    cnt[answers[i]] -= answers[i] + 1;
                    res += answers[i] + 1;
                }
            }
    
            return res;
        }
    };