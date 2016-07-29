// Two queue iterative approach
public boolean isSymmetric(TreeNode root) {
    Queue<TreeNode> rightFirst = new LinkedList<>();
    Queue<TreeNode> leftFirst = new LinkedList<>();
    rightFirst.add(root);
    leftFirst.add(root);
    while (!rightFirst.isEmpty()) { // assert !rightFirst.isEmpty() == !leftFirst.isEmpty()
        TreeNode right = rightFirst.remove();
        TreeNode left = leftFirst.remove();
        if (right == null && left == null) {
            continue;
        } else if (right != null && left != null && right.val == left.val) {
                rightFirst.add(right.right);
                rightFirst.add(right.left);
                leftFirst.add(left.left);
                leftFirst.add(left.right);

        } else {
            return false;
        }
    }
    return true;
}
