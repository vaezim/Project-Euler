########################################
#
# If root is an even/odd number, every
# odd/even number is a child of the first
# child of the root. Furthermore, children
# can be found as follows:
#  N (odd)
# [N-2, N-4, N-8, ..., N-2^n > 0]
# ^---^ => N' = N-2
# [N'-4, N'-8, N'-16, ..., N'-2^n > 0]
# ^----^ => N" = N'-4
# [N"-8, N"-16, N"-32, ..., N"-2^n > 0]
# .
# .
# .
#
########################################

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.children = []


if __name__ == "__main__":
    root = TreeNode(17)
    target = TreeNode(5)
    target_reached = False
    currNode = root

    level = 1 # Level in the tree (root at level 0)
    while True:
        val = currNode.val - 2**level
        if val < 0:
            break

        i = 1 # Node index at this level
        while val > 0:
            currNode.children.append(TreeNode(val))
            if val == target:
                target_reached = True
                break
            val -= 2 ** i
            i += 1

        currNode = currNode.children[0]
        level += 1
        if target_reached:
            break
