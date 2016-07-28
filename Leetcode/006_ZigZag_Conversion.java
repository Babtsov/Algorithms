// Strategy #1
public String convert(String s, int numRows) {
    if (numRows <= 1) {
        return s;
    }
    int leap = 2 * numRows - 2;
    StringBuilder sBuilder = new StringBuilder(s.length());
    for (int j = 0; j < s.length(); j += leap) {
        sBuilder.append(s.charAt(j));
    }
    for (int i = 1; i < numRows - 1 && i < s.length(); i++) {
        sBuilder.append(s.charAt(i));
        int oscillate = leap - 2 * i;
        for (int j = i + oscillate; j < s.length(); j += oscillate) {
            sBuilder.append(s.charAt(j));
            oscillate = leap - oscillate;
        }
    }
    for (int j = numRows - 1; j < s.length(); j += leap) {
        sBuilder.append(s.charAt(j));
    }
    return sBuilder.toString();
}

// Strategy #2 (perhaps easier to understand but likely less efficient)
public String convert(String s, int numRows) {
    ArrayList<Character>[] rows = (ArrayList<Character>[]) new ArrayList[numRows];
    for (int i = 0; i < numRows; i++) {
        rows[i] = new ArrayList<Character>();
    }
    for (int i = 0, n = s.length(); i < n; /* i++ is in the nested loops */) {
        for (int j = 0; i < n && j < numRows; j++, i++) {
            rows[j].add(s.charAt(i));
        }
        for (int j = numRows - 2; i < n && j > 0; j--, i++) {
            rows[j].add(s.charAt(i));
        }
    }
    StringBuilder sBuilder = new StringBuilder(s.length());
    for (int row = 0; row < numRows; row++) {
        for (int j = 0, rowLen = rows[row].size(); j < rowLen; j++) {
            sBuilder.append(rows[row].get(j));
        }
    }
    return sBuilder.toString();
}
