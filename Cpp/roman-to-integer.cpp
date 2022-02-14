https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/878/

#include <map>
class Solution {
public:
    int romanToInt(string s) {
        std::map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
       
        // for (std::map<std::string, int>::const_iterator it = roman.begin(); it != roman.end(); ++it) {
        //     cout << it->first;
        // }
        int number = 0;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case 'I':
                    if (roman[s[i + 1]] > roman[s[i]]) {
                        number += roman[s[i + 1]] - roman[s[i]];
                        i++; 
                    }
                    else {
                        number += roman[s[i]];
                    }
                    break;
                case 'V':
                    number += roman[s[i]];
                    break;
                case 'X':
                    if (roman[s[i + 1]] > roman[s[i]]) {
                        number += roman[s[i + 1]] - roman[s[i]];
                        i++; 
                    }
                    else {
                        number += roman[s[i]];
                    }
                    break;
                case 'L':
                    number += roman[s[i]];
                    break;
                case 'C':
                    if (roman[s[i + 1]] > roman[s[i]]) {
                        number += roman[s[i + 1]] - roman[s[i]];
                        i++; 
                    }
                    else {
                        number += roman[s[i]];
                    }
                    break;
                case 'D':
                    number += roman[s[i]];
                    break;
                case 'M':
                    number += roman[s[i]];
                    break;
                default: return number;
            }
       
        }

        return number;
    }
};