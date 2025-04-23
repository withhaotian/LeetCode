class Solution {
    public:
        int countLargestGroup(int n) {
            unordered_map<int, int> cnt;
    
            int max_val = 0;
            for(int i = 1; i <= n; i++) {
                int num = i;
                int sum = 0;
                while(num) {
                    sum += num % 10;
                    num /= 10;
                }
    
                cnt[sum] ++;
                if(cnt[sum] > max_val) {
                    max_val = cnt[sum];
                }
            }
    
            int res = 0;
            for(auto it : cnt) {
                if(it.second == max_val)    res ++;
            }
    
            return res;
        }
    };