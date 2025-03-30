class Solution {
    public:
        string addSpaces(string s, vector<int>& spaces) {
            string res = "";
            int l = 0; 
            int r = spaces.size();
            for (int i = 0; i < s.size(); i++) {
                if (l < r) {
                    if (spaces[l] == i) {
                        res += " ";
                        l++;
                    }
                }
                res += s[i];
            }     
    
            return res;
        }
    };