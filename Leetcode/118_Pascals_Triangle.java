public List<List<Integer>> generate(int numRows) {
    List<List<Integer>> traingle = new ArrayList<>(numRows);
    if (numRows < 1) {
        return traingle;
    }
    traingle.add(Arrays.asList(1));
    for (int i = 1; i < numRows; i++) {
        List<Integer> row = new ArrayList<>(i + 1);
        List<Integer> previousRow = traingle.get(i - 1);
        row.add(1);
        for (int j = 0, n = previousRow.size(); j < n - 1; j++) {
            row.add(previousRow.get(j) + previousRow.get(j + 1));
        }
        row.add(1);
        traingle.add(row);
    }
    return traingle;
}
