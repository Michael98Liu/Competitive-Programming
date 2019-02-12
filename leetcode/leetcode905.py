class Solution(object):
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        l = []
        for i in A:
            if i %2 == 0: l.append(i)
        for i in A:
            if i %2 != 0: l.append(i)

        return l
        
