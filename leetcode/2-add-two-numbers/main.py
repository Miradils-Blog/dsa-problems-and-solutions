from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = tail = ListNode()

        a: int
        b: int
        c: int
        carry = 0

        while (l1 or l2 or carry == 1):
            a = l1.val if l1 else 0
            b = l2.val if l2 else 0
            c = a + b + carry

            carry = c // 10
            tail.next = ListNode(c % 10)
            tail = tail.next

            if l1:
                l1 = l1.next

            if l2:
                l2 = l2.next

        return head.next
    

if __name__ == '__main__':
    l1 = ListNode(2, ListNode(4, ListNode(3)))
    l2 = ListNode(5, ListNode(6, ListNode(4)))

    res = Solution().addTwoNumbers(l1, l2)

    while res:
        print(res.val, end="")
        res = res.next