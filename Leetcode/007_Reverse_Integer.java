public int reverse(int x) {
    int sign = (x < 0)? -1 : 1;
    x *= sign;
    long answer = 0;
    while (x > 0) {
        int digit = x % 10;
        answer = 10 *answer + digit;
        x /= 10;
    }
    if (answer > Integer.MAX_VALUE) return 0;
    return sign * (int)answer;
}
