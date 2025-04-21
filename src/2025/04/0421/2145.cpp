class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int n = differences.size();
    
            long long min_val = 0;
            long long max_val = 0;
            long long sum_ = 0;
            for (int i = 0; i < n; i++) {
                sum_ += differences[i];
                min_val = min(min_val, sum_);
                max_val = max(max_val, sum_);
            }
    
            int res = upper - lower + 1 - max_val + min_val;
    
            return max(res, 0);
        }
    };