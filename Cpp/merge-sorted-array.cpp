// https://leetcode.com/explore/interview/card/bloomberg/68/array-and-strings/392/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> newNums1 = getSubarray(nums1, 0, nums1.size() - n);
        
        for (int i = 0; i < nums2.size(); i++) {
            newNums1.push_back(nums2[i]);
        }
        sort(begin(newNums1), end(newNums1));
        nums1 = newNums1;
        
    }
    
    vector<int> getSubarray(vector<int> array, int startPos,int endPos) {
        vector<int> newArray;
        for (int i = startPos; i < endPos; i++) {
            newArray.push_back(array[i]);
        }
        return newArray;
    }
};

// Solutions
/*

Approach 1: Merge and sort

Intuition

A naive approach would be to simply write the values from nums2 into the end of nums1, and then sort nums1. Remember that we do not need to return a value, as we should modify nums1 in-place. While straightforward to code, this approach has a high time complexity as we're not taking advantage of the existing sorting.

Java

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[i + m] = nums2[i];
        }
        Arrays.sort(nums1);
    }
}

Python

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # Write the elements of num2 into the end of nums1.
        for i in range(n):
            nums1[i + m] = nums2[i]
        
        # Sort nums1 list in-place.
        nums1.sort()



Approach 2: Three Pointers (Start From the Beginning)


Intuition

Because each array is already sorted, we can achieve an \mathcal{O}(n + m)O(n+m) time complexity with the help of the two-pointer technique.

Algorithm

The simplest implementation would be to make a copy of the values in nums1, called nums1Copy, and then use two read pointers and one write pointer to read values from nums1Copy and nums2 and write them into nums1.

Initialize nums1Copy to be a new array containing the first m values of nums1.
Initialize read pointer p1 to the beginning of nums1Copy.
Initialize read pointer p2 to the beginning of nums2.
Initialize write pointer p to the beginning of nums1.
While p is still within nums1:
If nums1Copy[p1] exists and is less than or equal to nums2[p2]:
Write nums1Copy[p1] into nums1[p], and increment p1 by 1.
Else
Write nums2[p2] into nums1[p], and increment p2 by 1.
Increment p by 1.

Java 

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // Make a copy of the first m elements of nums1.
        int[] nums1Copy = new int[m];
        for (int i = 0; i < m; i++) {
            nums1Copy[i] = nums1[i];
        }

        // Read pointers for nums1Copy and nums2 respectively.
        int p1 = 0;
        int p2 = 0;
                
        // Compare elements from nums1Copy and nums2 and write the smallest to nums1.
        for (int p = 0; p < m + n; p++) {
            // We also need to ensure that p1 and p2 aren't over the boundaries
            // of their respective arrays.
            if (p2 >= n || (p1 < m && nums1Copy[p1] < nums2[p2])) {
                nums1[p] = nums1Copy[p1++];
            } else {
                nums1[p] = nums2[p2++];
            }
        }
    }
}

Python

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # Make a copy of the first m elements of nums1.
        nums1_copy = nums1[:m] 
        
        # Read pointers for nums1Copy and nums2 respectively.
        p1 = 0
        p2 = 0
        
        # Compare elements from nums1Copy and nums2 and write the smallest to nums1.
        for p in range(n + m):
            # We also need to ensure that p1 and p2 aren't over the boundaries
            # of their respective arrays.
            if p2 >= n or (p1 < m and nums1_copy[p1] <= nums2[p2]):
                nums1[p] = nums1_copy[p1] 
                p1 += 1
            else:
                nums1[p] = nums2[p2]
                p2 += 1

                Time complexity: \mathcal{O}(n + m)O(n+m).

We are performing n + 2 \cdot mn+2⋅m reads and n + 2 \cdot mn+2⋅m writes. Because constants are ignored in Big O notation, this gives us a time complexity of \mathcal{O}(n + m)O(n+m).

Space complexity: \mathcal{O}(m)O(m).

We are allocating an additional array of length mm


Approach 3: Three Pointers (Start From the End)

Intuition

Interview Tip: This is a medium-level solution to an easy-level problem. Many of LeetCode's easy-level problems have more difficult solutions, and good candidates are expected to find them.

Approach 2 already demonstrates the best possible time complexity, \mathcal{O}(n + m)O(n+m), but still uses additional space. This is because the elements of array nums1 have to be stored somwhere so that they aren't overwritten.

So, what if instead we start to overwrite nums1 from the end, where there is no information yet?

The algorithm is similar to before, except this time we set p1 to point at index m - 1 of nums1, p2 to point at index n - 1 of nums2, and p to point at index m + n - 1 of nums1. This way, it is guaranteed that once we start overwriting the first m values in nums1, we will have already written each into its new position. In this way, we can eliminate the additional space.

Interview Tip: Whenever you're trying to solve an array problem in-place, always consider the possibility of iterating backwards instead of forwards through the array. It can completely change the problem, and make it a lot easier.

Java

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // Set p1 and p2 to point to the end of their respective arrays.
        int p1 = m - 1;
        int p2 = n - 1;
        
        // And move p backwards through the array, each time writing
        // the smallest value pointed at by p1 or p2.
        for (int p = m + n - 1; p >= 0; p--) {
            if (p2 < 0) {
                break;
            }
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1--];
            } else {
                nums1[p] = nums2[p2--];
            }
        }
    }
}


Python

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        
        # Set p1 and p2 to point to the end of their respective arrays.
        p1 = m - 1
        p2 = n - 1
    
        # And move p backwards through the array, each time writing
        # the smallest value pointed at by p1 or p2.
        for p in range(n + m - 1, -1, -1):
            if p2 < 0:
                break
            if p1 >= 0 and nums1[p1] > nums2[p2]:
                nums1[p] = nums1[p1]
                p1 -= 1
            else:
                nums1[p] = nums2[p2]
                p2 -= 1
                
*/