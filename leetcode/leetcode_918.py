class Solution:
    def maxSubarraySumCircular(self, nums):
        """
        :type A: List[int]
        :rtype: int
        """
        n = len(nums)
        startInd = len(nums) - 1
        while nums[startInd] >= 0 and startInd > 0:
            startInd -= 1
        if nums[startInd] < 0:
            startInd += 1

        dp = [startInd%n]*len(nums)
        dp[startInd%n] = nums[startInd%n]
        maxsum = dp[startInd%n]

        for i in range(1, len(nums)):
            if dp[(startInd +i-1)%n] > 0:
                dp[(startInd +i)%n] = nums[(startInd +i)%n] + dp[(startInd +i-1)%n]
            else:
                dp[(startInd +i)%n] = nums[(startInd +i)%n]
            maxsum = dp[(startInd +i)%n] if maxsum < dp[(startInd +i)%n] else maxsum
        '''
        for j in range(0, maxind):
            if dp[len(nums)+j-1] > 0:
                dp[len(nums)+j] = nums[j] + dp[len(nums)+j-1]
            else:
                dp[len(nums)+j] = nums[j]
            maxsum = dp[len(nums)+j] if maxsum < dp[len(nums)+j] else maxsum
        '''


        return maxsum


dp = [0]*len(nums)
        maxs = [0]*len(nums)

        dp[0] = nums[0]
        maxsum = dp[0]
        maxs[0] = maxsum
        for i in range(1, len(nums)):
            if dp[i-1] > 0:
                dp[i] = nums[i] + dp[i-1]
            else:
                dp[i] = nums[i]
            maxsum = dp[i] if maxsum < dp[i] else maxsum
            maxs[i] = maxsum

        print(maxs)
        reverse = [0]*len(nums)
        ind = len(nums)-1
        reverse[ind] = nums[ind]
        ind -= 1
        while ind >= 0:
            reverse[ind] = reverse[ind+1] + nums[ind]
            ind -= 1

        ans = reverse[0]

        for i in range(1, len(nums)):
            if reverse[i] + maxs[i-1] > ans:
                ans = reverse[i] + maxs[i-1]
        if maxs[-1] > ans: ans = maxs[-1]
        print(reverse)
