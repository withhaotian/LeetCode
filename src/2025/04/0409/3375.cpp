class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int n = nums.size();
    
            unordered_map<int, int> num_cnt;
    
            for(auto num : nums) {
                if (num < k) 
                    return -1;
                if (num > k)
                    num_cnt[num] ++;
            }
    
            return num_cnt.size();
        }
    };