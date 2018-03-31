# Referenced:
# https://leetcode.com/problems/jump-game-ii/discuss/18014/Concise-O(n)-one-loop-JAVA-solution-based-on-Greedy
# key: to make a jump, make sure every next jump could reach the furthest place

class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        furthest = 0
        hop = 0
        i = 0
        while i < len(nums)-1:
            for j in range(i, i + nums[i] + 1):
                if (j + nums[j]) > furthest:
                    furthest = j + nums[j]
                    des = j
                if j >= len(nums) - 1:
                    des = j
                    break
            hop += 1

            i = des
            print(i, furthest, hop)
        return hop
