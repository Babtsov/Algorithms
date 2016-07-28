public int coinChange(int[] coins, int amount) {
    int[] bestAmounts = new int[amount + 1];
    bestAmounts[0] = 0;
    for (int i = 1; i <= amount; i++) {
        int bestCandidate = Integer.MAX_VALUE;
        for (int j = 0; j < coins.length; j++) {
            int remainder = i - coins[j];
            if (remainder < 0 || bestAmounts[remainder] == Integer.MAX_VALUE) {
                continue;
            }
            bestCandidate = Math.min(bestAmounts[remainder] + 1, bestCandidate);
        }
        bestAmounts[i] = bestCandidate;
    }
    return (bestAmounts[amount] == Integer.MAX_VALUE)? -1 : bestAmounts[amount];
}
