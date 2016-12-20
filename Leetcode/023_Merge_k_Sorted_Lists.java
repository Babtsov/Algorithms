public ListNode mergeKLists(ListNode[] lists) {
    ListNode sorted = new ListNode(Integer.MAX_VALUE); // sentinel
    ListNode current = sorted;
    PriorityQueue<ListNode> pq = new PriorityQueue<ListNode>(1, new Comparator<ListNode>() {
        public int compare(ListNode a, ListNode b) {
            return a.val - b.val;
        }
    });
    for (int i = 0; i < lists.length; i++) {
        if (lists[i] != null) pq.add(lists[i]);
    }
    while (pq.size() != 0) {
        ListNode elem = pq.poll();
        current.next = elem;
        if (elem.next != null) pq.add(elem.next);
        current = current.next;
    }
    return sorted.next;
}
