#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
    
            vector<int> prefix_max(n);
            vector<int> suffix_max(n);
            
            prefix_max[0] = nums[0];
            for(int i = 1; i < n; i++) {
                prefix_max[i] = max(prefix_max[i-1], nums[i]);
            }
    
            suffix_max[n-1] = nums[n-1];
            for(int i = n - 2; i >= 0; i--) {
                suffix_max[i] = max(suffix_max[i+1], nums[i]);
            }
    
            long long res = 0;
            for(int i = 1; i < n-1; i++) {
                res = max(res, (long long)(prefix_max[i-1] - nums[i]) * suffix_max[i+1]);
            }
            
            return res;
        }
    };

int main() { 
    vector <int> nums = {12,6,1,2,7};
    
    Solution sol;
    cout << sol.maximumTripletValue(nums) << endl;

    return 0;
}