public ListNode removeNthFromEnd(ListNode head, int n) {
    ListNode first = head, second = head;
    int i;
    for (i = 0; i <= n && first != null ; i++) {
        first = first.next;
    }
    while (first != null) {
        first = first.next;
        second = second.next;
        i++;
    }
    if (i == n) {
        return head.next;
    }
    second.next = second.next.next;
    return head;
}
