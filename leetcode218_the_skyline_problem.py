# https://leetcode.com/problems/the-skyline-problem/description/

class Maxheap:
    def __init__(self):
        self.list = []

    def insert(self, x):
        self.list.append(x)
        self.percolateup()

    def percolateup(self):
        ind = len(self.list) - 1
        # compare with parents
        while ind != 0:
            if self.list[int((ind-1)/2)][2] < self.list[ind][2]:
                self.swap(ind, int((ind-1)/2))
                ind = int((ind-1)/2)
            else:
                break

    def deletemax(self):
        ret = self.list[0]
        self.list[0] = self.list[-1]
        self.list.pop()
        self.percolatedown()
        return ret

    def percolatedown(self):
        ind = 0
        while 2*ind + 1 < len(self.list):
            if 2*ind + 2 >= len(self.list):
                if self.list[ind][2] < self.list[2*ind + 1][2]:
                    self.swap(ind, 2*ind + 1)
                    ind = 2*ind + 1
                    break
                else: break
            elif self.list[2*ind + 1][2] < self.list[2*ind + 2][2]:
                if self.list[ind][2] < self.list[2*ind + 2][2]:
                    self.swap(ind, 2*ind + 2)
                    ind = 2*ind + 2
                else: break
            else:
                if self.list[ind][2] < self.list[2*ind + 1][2]:
                    self.swap(ind, 2*ind + 1)
                    ind = 2*ind + 1
                else: break

    def swap(self, i, j):
        temp = self.list[i]
        self.list[i] = self.list[j]
        self.list[j] = temp

    def printheap(self):
        for i in self.list:
            print(i, end=' ')
        print()

def getKey(i):
    return i[0]

class Solution:
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        maxh = Maxheap()
        heighest = 0
        next = 0
        ret = []
        extra = []

        for i in buildings:
            extra.append([i[1], -1, i[2]])
        buildings.extend(extra)
        sortedb = sorted(buildings, key = getKey)
        #print(sortedb)

        for i in sortedb:
            maxh.printheap()
            print("Skyline ", ret)
            print(i)
            if i[1] > 0:
                maxh.insert(i)
                if i[2] > heighest:
                    heighest = i[2]
                    # check previous one, make sure the height is different
                    if ret and ret[-1][1] == i[2]:
                        pass
                    else:
                        # make sure xcor is different
                        if ret and ret[-1][0] == i[0]:
                            if ret[-1][1] < heighest:
                                ret[-1][1] = heighest
                            else:
                                ret.append([i[0], heighest])
                        else:
                            ret.append([i[0], heighest])
            elif i[1] < 0:
                if i[2] == heighest and maxh.list[0][1] == i[0]:
                    maxh.deletemax()
                    # then delete all 'dead' heights
                    while maxh.list and maxh.list[0][1] <= i[0]:
                        maxh.deletemax()
                    if maxh.list:
                        heighest = maxh.list[0][2]
                        if ret and ret[-1][1] == heighest:
                            pass
                        else:
                            # make sure xcor is different
                            if ret and ret[-1][0] == i[0]:
                                if ret[-1][1] < heighest:
                                    ret[-1][1] = heighest
                                else:
                                    ret.append([i[0], heighest])
                            else:
                                ret.append([i[0], heighest])
                    else:
                        heighest = 0
                        ret.append([i[0], 0])



            #ret.append([i[0], maxh.list[0]])


        return ret


if __name__ == '__main__':
    building = [ [2,9,10], [3,7,15], [5,12,12], [15,20,10], [19,24,8] ]
    b2 = [[0,2,3],[2,5,3]]
    b3 = [[1,2,1],[1,2,2],[1,2,3]]
    b4 = [[0,3,3],[1,5,3],[2,4,3],[3,7,3]]
    sol = Solution()
    print(sol.getSkyline(b4))
