class Solution {
    public:
        int countGoodNumbers(long long n) {
            int M = 1e9 + 7;
            long long N = n / 2;
            // base impl, O(n), TLE!
            // if (n % 2) {
            //     int res = ((20 ** N) * 5) % M;
            // }
            // else {
            //     int res = (20 ** N) % M;
            // }
    
            // fast power impl, O(logn)
            long long result = 1;
            long long base = 20;
            long long power = N;
            while (power > 0) {
                if (power % 2 == 1) {  // 或者用 (power & 1)
                    result = (result * base) % M;
                }
                base = (base * base) % M;
                power /= 2;  // 或者用 power >>= 1
            }
    
            if (n % 2)  result *= 5;
    
            return result % M;
        }
    };