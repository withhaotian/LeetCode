#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
    public:
        int max_len = 0;
        unordered_set<int> index_map;
        void dfs(vector<int>& nums, int pos, int len, vector<bool>& visit) {
            visit[pos] = true;
            if(index_map.find(nums[pos]) != index_map.end()) {
                max_len = max(max_len, len);
                return;
            }
    
            index_map.insert(nums[pos]);
            dfs(nums, nums[pos], len+1, visit);
            index_map.erase(nums[pos]);
        }
    
        int arrayNesting(vector<int>& nums) {
            int n = nums.size();
    
            vector<bool> visit(n, false);
    
            for(int i = 0; i < n; i++) {
                if(!visit[i]) {     // OPTIMIZATION: pruning
                    dfs(nums, i, 0, visit);
                }
            }
    
            return max_len;
        }
    };

int main() {
    Solution s;
    vector<int> nums = {5,4,0,3,1,6,2};
    cout << s.arrayNesting(nums) << endl;
    return 0; 
}