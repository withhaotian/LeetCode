class Solution {
    public:
        int countPrefixes(vector<string>& words, string s) {
            int n = words.size();
            int res = 0;
            int ns = s.size();
    
            for (int i = 0; i < n; i++) {
                int len = words[i].size();
                if(len > ns)
                    continue;
                int l = 0;
                int r = min(len, ns);
                
                while(l < r) {
                    if(words[i][l] != s[l]) 
                        break;
                    l ++;
                }
    
                if (l == r)  res ++;
            }
    
            return res;
        }
    };