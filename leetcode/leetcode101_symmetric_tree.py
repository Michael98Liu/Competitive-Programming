# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        thisLevel = [root]
        return self.bfs(thisLevel)

    def bfs(self, thisLevel):
        nextLevel = []
        if self.isEmpty(thisLevel): return True

        if self.checksym(thisLevel) == False: return False
        for i in thisLevel:
            if i != None:
                nextLevel.append(i.left)
                nextLevel.append(i.right)
            else:
                nextLevel.append(None)
        return self.bfs(nextLevel)

    def checksym(self, l):
        for i in range(len(l)):
            if l[i] == l[-i-1]:
                continue
            if l[i] == None or l[-i-1] == None:
                return False
            if l[i].val != l[-i-1].val:
                return False
        return True

    def isEmpty(self, l):
        for i in l:
            if i != None: return False
        return True

'''
a simpler solution in Java

public boolean isSymmetric(TreeNode root) {
    return isMirror(root, root);
}

public boolean isMirror(TreeNode t1, TreeNode t2) {
    if (t1 == null && t2 == null) return true;
    if (t1 == null || t2 == null) return false;
    return (t1.val == t2.val)
        && isMirror(t1.right, t2.left)
        && isMirror(t1.left, t2.right);
}
'''
