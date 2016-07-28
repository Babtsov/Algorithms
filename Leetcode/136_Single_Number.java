public int singleNumber(int[] nums) {
    HashSet<Integer> set = new HashSet<>();
    int sum = 0;
    for (int num : nums) {
        sum += num;
        if (set.contains(num)) {
            sum -= 2*num;
        } else {
            set.add(num);
        }
    }
    return sum;
}
