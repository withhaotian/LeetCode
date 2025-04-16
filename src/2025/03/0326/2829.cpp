class Solution {
    public:
        int minimumSum(int n, int k) {
            unordered_map<int, int> umap;
    
            vector<int> temp;
            int num = 1;
            while(temp.size() < n) {
                if (!umap[k - num]) {
                    temp.push_back(num);
                    umap[num] = 1;
                }
                num ++;
            }
    
            int res = 0;
            for (auto it : temp)
                res += it;
    
            return res;
        }
    };