/**
* The key to solving this problem is to notice two things:
* 1) We need to keep track of the absolute minimum value of the array. Each element of the array will be compared against
* the minimum value to find the maximum difference. 
* 2) when we find a new minimum, we don't update the maximum difference.
*/
public int maxProfit(int[] prices) {
    if (prices == null || prices.length < 2) {
        return 0;
    }
    int min = prices[0];
    int diff = 0;
    for (int i = 1; i < prices.length; i++) {
        int newDiff = prices[i] - min;
        if (newDiff < 0) { // detect new minimum price
            min = prices[i];
        } else if (newDiff > diff) {
            diff = newDiff;
        }
    }
    return diff;
}
