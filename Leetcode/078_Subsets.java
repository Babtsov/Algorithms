// iterative solution
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

// recursive solution
private void helper(List<List<Integer>> solution, ArrayList<Integer> subset, int[] nums, int index) {
    if (index == nums.length) {
        solution.add(subset);
        return;
    }
    ArrayList<Integer> exclude = new ArrayList<Integer>(subset);
    helper(solution, exclude, nums, index + 1);
    ArrayList<Integer> include = new ArrayList<Integer>(subset);
    include.add(nums[index]);
    helper(solution, include, nums, index + 1);
}
public List<List<Integer>> subsets(int[] nums) {
    List<List<Integer>> solution = new ArrayList<List<Integer>>();
    helper(solution, new ArrayList<Integer>(), nums, 0);
    return solution;
}
