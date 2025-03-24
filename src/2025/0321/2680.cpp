class Solution {
    public:
        long long maximumOr(vector<int>& nums, int k) {
            int n = nums.size();
            vector<long long> prefix_or(n);
            vector<long long> sufix_or(n);
    
            prefix_or[0] = 0;
            for (int i = 1; i < n; i++) {
                prefix_or[i] = prefix_or[i-1] | nums[i-1];
            }
    
            sufix_or[n-1] = 0;
            for (int i = n - 2; i >= 0; i--) {
                sufix_or[i] = sufix_or[i+1] | nums[i+1];
            }
    
            vector<long long> tmp_nums(n);
            for (int i = 0; i < n; i++) {
                long long val = nums[i];
                val = val << k;
                tmp_nums[i] = val;
            }
    
            long long res = 0;
            for (int i = 0; i < n; i++) {
                long long tmp = prefix_or[i] | tmp_nums[i] | sufix_or[i];
                res = max(res, tmp);
            }
    
            return res;
        }
    };