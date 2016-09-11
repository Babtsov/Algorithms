public static int removeDuplicates(int[] nums) {
    if (nums == null || nums.length == 0) {
        return 0;
    }
    int uniqueIndex = 1, currentElem = nums[0];
    for (int i = 1; i < nums.length; i++) {
        if (nums[i] != currentElem) {
            nums[uniqueIndex++] = currentElem = nums[i];
        }
    }
    return uniqueIndex;
}
