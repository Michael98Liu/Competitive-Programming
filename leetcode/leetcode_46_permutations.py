class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.n = len(nums)
        self.chosen = [False]*self.n
        self.result = []
        self.nums = nums
        self.permu = []
        self.search()
        return self.result

    def search(self):
        if len(self.permu) == self.n:
            self.result.append(self.permu[:])
        else:
            for i in range(self.n):
                if self.chosen[i] == True:
                    continue
                self.permu.append(self.nums[i])
                self.chosen[i] = True
                self.search()
                self.permu.pop()
                self.chosen[i] = False

sol = Solution()
print(sol.permute([1,2,3]))
