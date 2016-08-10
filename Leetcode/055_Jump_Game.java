public boolean canJump(int[] nums) {
    int maxLeapIndex = 0;
    for (int i = 0; i < nums.length; i++) {
        if (maxLeapIndex < i) {
            return false;
        }
        maxLeapIndex = Math.max(maxLeapIndex, i + nums[i]);
    }
    return true;
}
