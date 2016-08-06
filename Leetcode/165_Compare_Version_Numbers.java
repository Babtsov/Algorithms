public int compareVersion(String version1, String version2) {
    Object[] v1 = Arrays.stream(version1.split("\\.")).map(i->Integer.parseInt(i)).toArray();;
    Object[] v2 = Arrays.stream(version2.split("\\.")).map(i->Integer.parseInt(i)).toArray();;
    for (int i = 0, n = Math.max(v1.length, v2.length); i < n; i++) {
        int a = (i < v1.length) ? (int) v1[i]: 0;
        int b = (i < v2.length) ? (int) v2[i]: 0;
        if (a != b) {
            return (a > b) ? 1 : -1;
        }
    }
    return 0;
}
