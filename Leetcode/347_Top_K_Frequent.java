public List<Integer> topKFrequent(int[] nums, int k) {
    HashMap<Integer, Integer> freq = new HashMap<>();
    for (int num : nums) {
        int frequency = freq.containsKey(num) ? freq.get(num) + 1 : 1;
        freq.put(num, frequency);
    }
    PriorityQueue<Integer> pq = new PriorityQueue<>(k, (a, b) -> (freq.get(b) - freq.get(a)));
    pq.addAll(freq.keySet());
    ArrayList<Integer> topFrequent = new ArrayList<>(k);
    for (int i = 0; i < k; i++) {
        topFrequent.add(pq.poll());
    }
    return topFrequent;
}
