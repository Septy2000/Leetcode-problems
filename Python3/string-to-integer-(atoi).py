# https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/884/
class Solution:
    def myAtoi(self, s: str) -> int:
        # 0 for +, 1 for -
        sign = 0
        number = "0"
        s = s.strip()
        if s == "": return 0
        if s[0] == "+":
            sign = 0
            s = s[1:]
        elif s[0] == "-":
            sign = 1
            s = s[1:]

        for ch in s:
            if ch.isdigit():
                number += ch
            else:
                break
        number_int = int(number)
        if sign == 1: number_int = -number_int
        if number_int > 2**31 - 1:
            number_int = 2**31 - 1
        elif number_int < -(2**31):
            number_int = -(2**31) 
        return number_int
        