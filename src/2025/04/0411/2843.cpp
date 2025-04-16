class Solution {
    public:
        
        bool check(int val) {
            if (val >= 10 && val < 100) {
                int a = val % 10;
                int b = val / 10;
                return a == b;
            }
            else if(val >= 1000 && val < 10000) {
                int a = val / 100;
                int b = val % 100;
                int sum_a = a / 10 + a % 10;
                int sum_b = b / 10 + b % 10;
                return sum_a == sum_b;
            }
    
            return false;
        }
    
        int countSymmetricIntegers(int low, int high) {
            // only two or four digits are valid
            int res = 0;
    
            while(low <= high) {
                if(low < 10) {
                    low = 10;
                }
                else if(low >= 100 && low < 1000) {
                    low = 1000;
                }
    
                if (low <= high)
                    res += check(low);
                else
                    break;
                
                low ++;
            }
    
            return res;
        }
    };