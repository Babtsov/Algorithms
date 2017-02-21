public List<List<Integer>> subsets(int[] nums) {
    List<List<Integer>> solution = new ArrayList<List<Integer>>();
    for (int i = 0, subsetCount = 1 << nums.length; i < subsetCount; i++) {
        List<Integer> subset = new ArrayList<Integer>();
        for (int j = 0; j < nums.length; j++) {
            if ((i & (1 << j)) != 0) {
                subset.add(nums[j]);
            }
        }
        solution.add(subset);
    }
    return solution;
}
