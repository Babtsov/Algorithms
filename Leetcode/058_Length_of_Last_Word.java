public int lengthOfLastWord(String s) {
    int count = 0;
    boolean foundSomething = false;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s.charAt(i) == ' ') {
            if (foundSomething) break;
            else continue;
        }
        foundSomething = true;
        count++;
    }
    return count;
}
