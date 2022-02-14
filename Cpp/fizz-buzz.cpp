// https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/743/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int i = 1; i <= n; i++) {
            string output = "";
            if (i % 3 == 0) {
                output += "Fizz";
            }
            if (i % 5 == 0) {
                output += "Buzz";
            }
            if (output == "") {
                output += to_string(i);
            }
            result.push_back(output);
        }
        return result;
        
        
    }
    
    
    
};