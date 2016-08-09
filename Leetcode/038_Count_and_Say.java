public String countAndSay(int n) {
    String string = "1";
    for (int i = 1; i < n; i++) {
        char current = string.charAt(0);
        int count = 1;
        StringBuilder sBuilder = new StringBuilder();
        for (int j = 1; j < string.length(); j++) {
            if (string.charAt(j) != current) {
                sBuilder.append(count);
                sBuilder.append(current);
                current = string.charAt(j);
                count = 1;
            } else {
                count++;
            }
        }
        sBuilder.append(count);
        sBuilder.append(current);
        string = sBuilder.toString();
    }
    return string;
}
