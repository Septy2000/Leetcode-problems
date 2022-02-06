# https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/887/

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        min_len = 1000
        pref = ""
        for str in strs:
            if len(str) < min_len: 
                min_len = len(str)
        if min_len == 0: return ""
        for i in range(min_len):
            letter = strs[0][i] 
            for str in strs:
                if str[i] != letter:
                    return pref
            pref += letter
        return pref