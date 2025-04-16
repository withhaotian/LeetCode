class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            unordered_map<int, int> num_cnt_pairs;
    
            long long res = 0;
            long long match = 0;
            int j = -1;
            for (int i = 0; i < nums.size(); i++) {
                while(match < k && j + 1 < nums.size()) {
                    ++j;
                    match += num_cnt_pairs[nums[j]];
                    num_cnt_pairs[nums[j]]++;
                }
                if (match >= k) {
                    res += nums.size() - j;
                }
                num_cnt_pairs[nums[i]] --;
                match -= num_cnt_pairs[nums[i]];
            }
    
            return res;
    
        }
    };