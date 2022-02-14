https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/744/

// Sieve of Eratosthenes method

#include <vector>
#include <math.h>
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        
        std::vector<bool> numbers(n);
        for (int i = 2; i <= sqrt(n); i++) {
            if (!numbers[i]) {
                for (int j = i*i; j < n; j += i) {
                    numbers[j] = true;
                }
            }
        }
        
        int primes = 0;
        for (int i = 2; i < n; i++) {
            if (!numbers[i]) {
                primes++;
            }
        }
        
        return primes;
    }
};