class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows == 1)  return s;
    
            int n = s.size();
            vector<string> num_str(numRows);
    
            int flag = -1;
            int row = 0;
            for(int i = 0; i < n; i++) {
                num_str[row].push_back(s[i]);
                if (row == 0 || row == numRows - 1)
                    flag = -flag;
                row += flag;
            }
    
            string res = "";
            for (int i = 0; i < numRows; i++) {
                res += num_str[i];
            }
    
            return res;
        }
    };