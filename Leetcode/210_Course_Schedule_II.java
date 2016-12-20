// see https://en.wikipedia.org/wiki/Topological_sorting
private class Node {
    public ArrayList<Integer> prerequisites = new ArrayList<Integer>();
    boolean temporaryMark = false;
    boolean permanentMark = false;
}
private boolean visit(Node[] graph, int node, ArrayList<Integer> order) {
    if (graph[node].permanentMark) return true;
    if (graph[node].temporaryMark) return false;
    graph[node].temporaryMark = true;
    ArrayList<Integer> prerequisites = graph[node].prerequisites;
    for (int i = 0; i < prerequisites.size(); i++) {
        boolean isValid = visit(graph, prerequisites.get(i), order);
        if (!isValid) return false;
    }
    graph[node].temporaryMark = false;
    order.add(node);
    graph[node].permanentMark = true;
    return true;
}
public int[] findOrder(int numCourses, int[][] prerequisites) {
    Node[] graph = new Node[numCourses];
    for (int i = 0; i < numCourses; i++) {
        graph[i] = new Node();
    }
    for (int i = 0; i < prerequisites.length; i++) {
        int[] pair = prerequisites[i];
        graph[pair[0]].prerequisites.add(pair[1]);
    }
    ArrayList<Integer> order = new ArrayList<Integer>();
    for (int i = 0; i < numCourses; i++) {
        boolean isValid = visit(graph, i, order);
        if (!isValid) return new int[0];
    }
    int[] ret = new int[numCourses];
    for (int i = 0; i < numCourses; i++) {
        ret[i] = order.get(i);
    }
    return ret;
}
