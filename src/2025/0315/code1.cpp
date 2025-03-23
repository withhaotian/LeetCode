/*
给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。

如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。

 

示例 1：

输入：nums = [1,2,3,4,5]
输出：true
解释：任何 i < j < k 的三元组都满足题意
示例 2：

输入：nums = [5,4,3,2,1]
输出：false
解释：不存在满足题意的三元组
示例 3：

输入：nums = [2,1,5,0,4,6]
输出：true
解释：三元组 (3, 4, 5) 满足题意，因为 nums[3] == 0 < nums[4] == 4 < nums[5] == 6
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        vector<int> min_nums(nums.size());
        vector<int> max_nums(nums.size());
        
        min_nums[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            min_nums[i] = min(min_nums[i-1], nums[i]);
        }
        
        max_nums[nums.size()-1] = nums[nums.size()-1];
        for (int i = nums.size()-2; i >= 0; i--) {
            max_nums[i] = max(max_nums[i+1], nums[i]);
        }

        for (int i = 1; i <= nums.size()-2; i++) {
            if (nums[i] > min_nums[i-1] && nums[i] < max_nums[i+1])
                return true;
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,5,0,4,1,3};
    cout << s.increasingTriplet(nums) << endl;
    return 0;
}