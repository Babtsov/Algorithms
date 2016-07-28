// recursive strategy: 
// 1) keep track of the path from the root of the tree to the current node we are visiting, in a "stack-like" data structure. 
// The path is stored in an ArrayList, and we push and pop according to what level we are in the recursion.
// 2) if we reached a leaf, iterate backwards through the path, summing up each number accordingly. return the result.
public int sumNumbers(TreeNode root) {
    return helper(root, new ArrayList<>());
}
public int helper(TreeNode root,ArrayList<TreeNode> pathToNode) {
    if (root == null) {
        return 0;
    }
    pathToNode.add(root); // push
    int sum = helper(root.left, pathToNode) + helper(root.right, pathToNode);
    if (sum == 0) { // means we have a leaf (both children were null)
        for (int i = pathToNode.size() - 1, decima = 1; i >= 0; i--, decima *= 10) {
            sum += decima * pathToNode.get(i).val;
        }
    }
    pathToNode.remove(pathToNode.size() - 1); // pop
    return sum;
}

// Optimized recusrive strategy:
// Instead of keeping track of the path in a "stack-like" data structure, keep track of the total.
public int sumNumbers(TreeNode root) {
    return helper(root, 0);
}
public int helper(TreeNode root, int total) {
    if (root == null) {
        return 0;
    }
    if (root.left == null && root.right == null) {
        return total + root.val;
    }
    return helper(root.left, (total + root.val) * 10) + helper(root.right, (total + root.val) * 10);
}
// iterative in order strategy
public int sumNumbers(TreeNode root) {
    if (root == null) {
        return 0;
    }
    Stack<TreeNode> nodes = new Stack<>();
    nodes.push(root);
    Stack<Integer> totals = new Stack<>();
    totals.push(root.val);
    int sum = 0;
    while (!nodes.isEmpty()) {
        TreeNode node = nodes.pop();
        int total = totals.pop();
        if (node.right != null) {
            nodes.push(node.right);
            totals.push(total * 10 + node.right.val);
        }
        if (node.left != null) {
            nodes.push(node.left);
            totals.push(total * 10 + node.left.val);
        }
        if (node.left == null && node.right == null) {
            sum += total;
        }
    }
    return sum;
}
