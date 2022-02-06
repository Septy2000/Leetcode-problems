# https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/885/

# class Solution:
#     def strStr(self, haystack: str, needle: str) -> int:      
#         if needle == "": return 0
#         if len(needle) > len(haystack): return -1

#         for i in range(len(haystack)):
#             if needle[0] == haystack[i]:
#                 if self.checkx(haystack[i:], needle): return i
#         return -1

#     def checkx(self, haystack: str, needle: str) -> bool:
#         if len(needle) > len(haystack): return False
#         else:
#             for i in range(len(needle)):
#                 if needle[i] != haystack[i]:
#                     return False
#             return True

# class Solution:
#     def strStr(self, haystack: str, needle: str) -> int:      
#         if len(needle) == 0: return 0
#         if len(haystack) == 0: return -1
#         if len(needle) > len(haystack): return -1

#         for i in range(len(haystack)):
#             if i + len(needle) > len(haystack): return -1
#             for j in range(len(needle)):
#                 if haystack[i + j] != needle[j]: break
#                 if j == len(needle) - 1: return i
#         return -1

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == '':
            return 0
        if needle in haystack:
            return haystack.index(needle)
        else:
            return -1



