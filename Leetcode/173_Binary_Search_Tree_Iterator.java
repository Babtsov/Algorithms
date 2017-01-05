public class BSTIterator {
    private Stack<TreeNode> stack = new Stack<TreeNode>();
    
    private void traverse(TreeNode node) {
        while (node != null) {
            stack.push(node);
            node = node.left;
        }
    }
    
    public BSTIterator(TreeNode root) {
        traverse(root);
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !stack.isEmpty();
    }

    /** @return the next smallest number */
    public int next() {
        TreeNode current = stack.pop();
        traverse(current.right);
        return current.val;
    }
}
