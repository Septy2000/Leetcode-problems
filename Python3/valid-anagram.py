# https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/
import collections


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count1 = collections.Counter(s)
        count2 = collections.Counter(t)
        return count1 == count2