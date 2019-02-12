class Solution(object):
    def totalFruit(self, tree):
        """
        :type tree: List[int]
        :rtype: int
        """
        if len(tree) > 2:
            a = tree[0]
            a_len = 1
            if tree[1] != tree[0]:
                b = tree[1]
                a_len = 0
                b_len = 1
            else:
                a_len = 2
                b_len = 0
                b = -1

            this_len = 2
            max_len = 2


            for i in range(2, len(tree)):
                if b == -1 and tree[i] != a:
                    b = tree[i]
                    this_len += 1
                    b_len = 1
                    a_len = 0
                elif tree[i] == a:
                    this_len += 1
                    if a_len == 0:
                        b_len = 0
                    a_len += 1
                elif tree[i] == b:
                    this_len += 1
                    if b_len == 0:
                        a_len = 0
                    b_len += 1
                else:
                    if this_len > max_len: max_len = this_len
                    #find the longest
                    a = tree[i-1]
                    b = tree[i]
                    this_len = a_len + b_len + 1
                    b_len = 1
                    a_len = 0

            if max_len < this_len: max_len = this_len
            return max_len
        elif len(tree) == 2:
            return 2
        else:
            return 1
