public int lengthLongestPath(String input) {
    ArrayList<Integer> path = new ArrayList<>();
    int pathIndex = 0;
    int currentLength = 0, maxPathLength = 0;
    boolean fileFound = false;
    for (int i = 0; i < input.length(); i++) {
        char c = input.charAt(i);
        if (c == '\n') {
            if (pathIndex == path.size()) {
                path.add(currentLength);
            } else {
                path.set(pathIndex, currentLength);
            }
            if (fileFound && currentLength > maxPathLength) maxPathLength = currentLength;
            fileFound = false;
            currentLength = pathIndex = 0;
        } else if (c == '\t') {
            currentLength = path.get(pathIndex) + 1;
            pathIndex++;
        } else {
            if (c == '.') fileFound = true;
            currentLength++;
            if (fileFound && currentLength > maxPathLength) maxPathLength = currentLength;
        }
    }
    return maxPathLength;
}
