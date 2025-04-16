class Solution {
    public:
        long long minimumCost(string s) {
            int len = s.size();
            
            vector<long long> prefix(len);
            vector<long long> suffix(len);
            
            prefix[0] = 0;
            for (int i = 1; i < len; i++) {
                if (s[i] == s[i-1])
                    prefix[i] = prefix[i-1];
                else
                    prefix[i] = prefix[i-1] + i;
            }
    
            suffix[len - 1] = 0;
            for (int i = len - 2; i >= 0; i--) {
                if (s[i] == s[i+1]) 
                    suffix[i] = suffix[i+1];
                else 
                    suffix[i] = suffix[i+1] + len - i - 1;
            }
    
            long long res = LLONG_MAX;
            for (int i = 0; i < len; i++) {
                res = min(res, prefix[i] + suffix[i]);
            }
    
            return res;
        }
    };