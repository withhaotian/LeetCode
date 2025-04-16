#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
    
            long long res = 0;
            
            // Solution 1 - three loop
            for (int i = 0; i < n-2; i++) {
                for (int j = i+1; j < n-1; j++) {
                    for (int k = j+1; k < n; k++) {
                        if (i < j && j < k) {
                            long long tmp = nums[i] - nums[j];
                            tmp *= nums[k];
                            res = max(res, tmp);
                        }
                    }
                }
            }
    
            // Solution 2 - greedy
            for (int k = 2; k < n; k++) {
                int max_i = nums[0];
                for (int j = 1; j < k; j++) {
                    long long tmp = (long long) (max_i - nums[j]) * nums[k];
                    res = max(res, tmp);
                    max_i = max(max_i, nums[j]);
                }
            }
    
            return res;
        }
    };

int main() {
    Solution s;
    vector<int> nums = {1000000,1,1000000};
    cout << s.maximumTripletValue(nums) << endl;
    return 0;
}