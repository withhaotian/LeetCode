class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            // j - nums[j] != i - nums[i]
            // collect all x - nums[x] using hash map
            unordered_map<int, long long> umap;
    
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                umap[i - nums[i]]++;
            }
    
            long long res = (long long)n * (n-1) / 2;
            for(const auto& it : umap) {
                if(it.second > 1)
                    res -= (it.second - 1) * it.second / 2;
            }
    
            return res;
        }
    };