class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        # check if either of the lists are empty
        if not l1:
            return l2
        if not l2:
            return l1

        # initialize the merged list with a dummy node
        merged_list = ListNode(-1)
        current = merged_list

        # compare the nodes in both lists and add them to the merged list in sorted order
        while l1 and l2:
            if l1.val <= l2.val:
                current.next = l1
                l1 = l1.next
            else:
                current.next = l2
                l2 = l2.next
            current = current.next

        # add any remaining nodes from the non-empty list to the merged list
        if l1:
            current.next = l1
        if l2:
            current.next = l2

        # return the merged list, starting from the node after the dummy node
        return merged_list.next
