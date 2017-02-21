// solution 1
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

// solution 2
public int lengthOfLastWord(String s) {
    int length = 0;
    int i = s.length() - 1;
    for (; i >= 0 && s.charAt(i) == ' '; i--)
        ;
    for (; i >= 0 && s.charAt(i) != ' ' ; i--) {
        length++;
    }
    return length;
}
