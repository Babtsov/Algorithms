public ListNode removeNthFromEnd(ListNode head, int n) {
    if (head == null || n <= 0) {
        throw new IllegalArgumentException();
    }
    ListNode dummyHead = new ListNode(0);
    dummyHead.next = head;
    ListNode first = dummyHead, second = dummyHead;
    for (int i = 0; i <= n; i++) {
        if (first == null) {
            throw new IllegalArgumentException();
        }
        first = first.next;
    }
    while (first != null) {
        first = first.next;
        second = second.next;
    }
    second.next = second.next.next;
    return dummyHead.next;
}
