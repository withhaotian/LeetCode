class Solution {
    public:
        struct SetHash {
            size_t operator()(const set<int>& s) const {
                size_t hash = 0;
                for (int i : s) {
                    hash ^= hash_fn(i) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
                }
                return hash;
            }
            
            hash<int> hash_fn;
        };
    
        unordered_map<set<int>, int, SetHash> countMap;
    
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            
            int result = 0;
            for (int i = 0; i < dominoes.size(); i++) {
                set<int> key = {dominoes[i][0], dominoes[i][1]};
                countMap[key]++;
            }
    
            for (auto it : countMap) {
                result += it.second * (it.second - 1) / 2;
            }
    
            return result;
        }
    };
    