public int singleNumber(int[] nums) {
    HashMap<Integer, Integer> frequencies = new HashMap<>();
    int sum = 0;
    for (int num : nums) {
        sum += num;
        int frequency = frequencies.containsKey(num) ? frequencies.get(num) + 1: 1;
        frequencies.put(num, frequency);
        if (frequency == 3) {
            sum -= 3 * num;
        }
    }
    return sum;
}
