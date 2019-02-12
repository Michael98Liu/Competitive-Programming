# https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn))-solution-with-explanation

class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m = len(nums1)
        n = len(nums2)
        beg = 0
        end = len(nums1) - 1

        if m > n:
            nums1, nums2, m, n = num2, nums1, n, m
        if n == 0:
            raise ValueError

        while beg <= end:
            ind1 = int((end+beg)/2)
            ind2 = int((m+n+1)/2) - ind1
            if ind1 < m and nums1[ind1] < nums2[ind2]:
                # ind1 is too small
                beg = ind1 + 1
            elif ind1 > n and nums1[ind1] > nums2[ind2]:
                # ind1 is too large
                end = ind1 - 1
            else:
                # ind1 is perfect
                if ind1 == 0: max_of_left = nums2[ind2-1]
                elif ind2 == 0: max_of_left = nums1[ind1-1]
                else: max_of_left = max(nums1[ind1-1], nums2[ind2-1])

                if (m + n) % 2 == 1:
                    return max_of_left

                    if ind1 == m: min_of_right = nums2[ind2]
                    elif ind2 == n: min_of_right = nums1[ind1]
                    else: min_of_right = min(nums1[ind1], nums2[ind2])

                    return (max_of_left + min_of_right) / 2.0


a1 = [1,2,3,4,5,12]
a2 = [6,8,9,10,11,13,14]
sol = Solution()
print(sol.findMedianSortedArrays(a1, a2))
