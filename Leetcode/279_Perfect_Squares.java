public int numSquares(int n) {
    int root = (int) Math.sqrt(n);
    int[] squares = new int[root];
    for (int i = 0; i < squares.length; i++) {
        squares[i] = (int) Math.pow(i + 1, 2);
    }
    int[] dp = new int[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int minCombinations = Integer.MAX_VALUE;
        for (int j = 0; j < squares.length; j++) {
            int remainder = i - squares[j];
            if (remainder < 0) {
                break;
            }
            minCombinations = Math.min(dp[remainder] + 1, minCombinations);
        }
        dp[i] = minCombinations;
    }
    return dp[n];
}
