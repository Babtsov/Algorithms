public List<Interval> merge(List<Interval> intervals) {
    List<Interval> solution = new ArrayList<Interval>();
    if (intervals.size() == 0) return solution;
    Collections.sort(intervals, new Comparator<Interval>() {
        public int compare(Interval lhs, Interval rhs) {
            return lhs.start - rhs.start;
        }
    });
    solution.add(new Interval(intervals.get(0).start, intervals.get(0).end));
    for (int i = 1; i < intervals.size(); i++) {
        Interval current = intervals.get(i);
        Interval prev = solution.get(solution.size() - 1);
        if (current.start <= prev.end && current.end > prev.end) {
            prev.end = current.end;
        } else if (current.start > prev.end) {
            solution.add(new Interval(intervals.get(i).start, intervals.get(i).end));
        }
    }
    return solution;
}
