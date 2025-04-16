#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
            int n = arr.size();
            int m = pieces.size();
            
            unordered_map<int, int> num_ord;
    
            for(int i = 0; i < n; i++) {
                num_ord[arr[i]] = i + 1;
            }
    
            for(int i = 0; i < m; i++) {
                if (pieces[i].size() > 1) {
                    for (int j = 0; j < pieces[i].size() - 1; j++) {
                        int loc_j = num_ord[pieces[i][j]];
                        int loc_j_next = num_ord[pieces[i][j+1]];
                        if(loc_j_next != loc_j + 1 || !loc_j || !loc_j_next)  return false;
                    }
                }
                else {
                    if (!num_ord[pieces[i][0]])  return false;
                }
            }
    
            return true;
        }
    };

int main() {
    Solution s;
    vector<int> arr = {91,4,64,78};
    vector<vector<int>> pieces = {{78},{4,64},{91}};
    cout << s.canFormArray(arr, pieces) << endl;
    return 0;
}