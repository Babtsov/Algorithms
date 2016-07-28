public int missingNumber(int[] nums) {
    int partialSum = 0;
    for (int i = 0; i < nums.length; i++) {
        partialSum += nums[i];
    }
    int target = nums.length * (nums.length + 1) / 2;
    return target - partialSum;
}
