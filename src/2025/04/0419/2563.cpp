class Solution {
    public:
        long long upper_bound(vector<int>& nums, int upper) {
            int n = nums.size();
            int l = 0;
            int r = n - 1;
    
            long long res = 0;
            while(l < r) {
                while (l < r && nums[l] + nums[r] > upper) {
                    r --;
                }
                if (l >= r) {
                    break;
                }
                res += (long long) r - l;
                l++;
            }
    
            return res;
        }
        
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            sort(nums.begin(), nums.end());
    
            return upper_bound(nums, upper) - upper_bound(nums, lower - 1);
        }
    };
    
    