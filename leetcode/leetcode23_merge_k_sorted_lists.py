# https://leetcode.com/problems/merge-k-sorted-lists/

class Heap:
    def __init__(self):
        self.list = []

    def insert(self, x):
        self.list.append(x)
        self.percolateup()

    def percolateup(self):
        ind = len(self.list) - 1
        # compare with parents
        while ind != 0:
            if self.list[int((ind-1)/2)].val > self.list[ind].val:
                self.swap(ind, int((ind-1)/2))
                ind = int((ind-1)/2)
            else:
                break

    def deletemin(self):
        ret = self.list[0]
        self.list[0] = self.list[-1]
        self.percolatedown()
        self.list.pop()
        return ret

    def percolatedown(self):
        ind = 0
        while 2*ind + 1 < len(self.list):
            if 2*ind + 2 >= len(self.list):
                if self.list[ind].val > self.list[2*ind + 1].val:
                    self.swap(ind, 2*ind + 1)
                    ind = 2*ind + 1
                    break
            if self.list[2*ind + 1].val > self.list[2*ind + 2].val:
                if self.list[ind].val > self.list[2*ind + 2].val:
                    self.swap(ind, 2*ind + 2)
                    ind = 2*ind + 2
                else:
                    break
            else:
                if self.list[ind].val > self.list[2*ind + 1].val:
                    self.swap(ind, 2*ind + 1)
                    ind = 2*ind + 1
                else:
                    break

    def swap(self, i, j):
        temp = self.list[i]
        self.list[i] = self.list[j]
        self.list[j] = temp

    def printheap(self):
        for i in self.list:
            print(i.val, end=" ")
        print()

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        ret = None
        h = Heap()
        for i in lists:
            if i != None:
                h.insert(i)
        #h.printheap()

        if len(h.list) != 0:
            ret = h.deletemin()
        else:
            return ret
        prev = ret
        while len(h.list) != 0:
            #h.printheap()
            if prev.next != None:
                h.insert(prev.next)
            min = h.deletemin()
            prev.next = min
            prev = min

        return ret
