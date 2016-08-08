public boolean hasCycle(ListNode head) {
    ListNode slow = head, fast = head;
    while(fast != null){
        slow = slow.next;
        fast = fast.next;
        if (fast != null) {
            fast = fast.next;
        }
        if (slow == fast && slow != null) {
            return true;
        }
    }
    return false;
}
