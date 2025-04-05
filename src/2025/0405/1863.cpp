#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int res = 0;
    
        void dfs(int val, int idx, vector<int>& nums) {
            if (idx == nums.size()) {
                res += val;
                return;
            }
    
            dfs(val ^ nums[idx], idx+1, nums);
            dfs(val, idx+1, nums);
        }
    
        int subsetXORSum(vector<int>& nums) {
            
            dfs(0, 0, nums);
    
            return res;
        }
    };

int main() {
    vector<int> nums = {3,4,5,6,7,8};
    Solution sol;
    cout << sol.subsetXORSum(nums) << endl;
    return 0;
}