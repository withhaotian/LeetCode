class Solution {
    public:
        vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
            vector<int> res(2, 0);
    
            for (int i = 0; i < mat.size(); i++) {
                int cnt = 0;
                for(int j = 0; j < mat[0].size(); j++) {
                    if (mat[i][j])  cnt ++;
                }
                if (cnt > res[1]) {
                    res[1] = cnt;
                    res[0] = i;
                }
            }
    
            return res;
        }
    };