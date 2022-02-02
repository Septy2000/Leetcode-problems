import re
class Solution:
    def isPalindrome(self, s: str) -> bool:
        newStr = ""
        s = re.sub(r'[^a-zA-Z0-9]', '', s)
        s = s.lower()
        print(s)
        return s == s[::-1]
        