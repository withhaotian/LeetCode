class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int n = tops.size();
            
            vector<int> cnt_top(7);
            vector<int> cnt_bot(7);
            int result = n;
            for (int i = 1; i <= 6; i++) {
                bool is_top = true;
                for (int j = 0; j < n; j++) {
                    if(tops[j] == i)    continue;
                    else if(bottoms[j] == i)    cnt_top[i] += 1;
                    else {
                        is_top = false;
                        break;
                    }
                }
    
                bool is_bottom = true;
                for (int j = 0; j < n; j++) {
                    if(bottoms[j] == i)    continue;
                    else if(tops[j] == i)    cnt_bot[i] += 1;
                    else {
                        is_bottom = false;
                        break;
                    }
                }
    
                if(is_top) {
                    result = min(result, cnt_top[i]);
                }
                if(is_bottom) {
                    result = min(result, cnt_bot[i]);
                }
            }
    
            return result == n ? -1 : result;
        }
    };