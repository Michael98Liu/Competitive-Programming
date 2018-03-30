# implementation for max heap

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
            if self.list[int((ind-1)/2)] < self.list[ind]:
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
                if self.list[ind] < self.list[2*ind + 1]:
                    self.swap(ind, 2*ind + 1)
                    ind = 2*ind + 1
                    break
            elif self.list[2*ind + 1] < self.list[2*ind + 2]:
                if self.list[ind] < self.list[2*ind + 2]:
                    self.swap(ind, 2*ind + 2)
                    ind = 2*ind + 2
                else: break
            else:
                if self.list[ind] < self.list[2*ind + 1]:
                    self.swap(ind, 2*ind + 1)
                    ind = 2*ind + 1
                else: break

    def swap(self, i, j):
        temp = self.list[i]
        self.list[i] = self.list[j]
        self.list[j] = temp

    def printheap(self):
        print(self.list)

if __name__ == "__main__":
    h = Maxheap()
    h.insert(100)
    h.insert(4)
    h.insert(3)
    h.insert(10)
    h.insert(6)
    h.insert(8)
    h.insert(7)
    h.insert(1)
    h.printheap()
