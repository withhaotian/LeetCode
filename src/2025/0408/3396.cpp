#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int n = nums.size();
    
            unordered_map<int, int> cnt_map;
    
            int res = 0;
    
            for (int i = n - 1; i >= 0; i--) {
                if(!cnt_map[nums[i]]) {
                    cnt_map[nums[i]] ++;
                }
                else {
                    res = (i+1) / 3;
                    if((i+1) % 3 != 0)
                        res += 1;
                    break;
                }
            }
    
            return res;
        }
    };

int main() {
    Solution s;
    vector<int> nums = {1,2,3,2,1,1,2,3,3};
    cout << s.minimumOperations(nums) << endl;
    return 0;
}