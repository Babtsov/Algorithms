// This 'codec' is for the most part consistent with how leetcode serializes and deserializes code, and at this point, not optimized for
// performance (for example, it involves safety checks to guard against invalid inputs in the deserialization function).
// Because of that, these two functions can be used as general utility functions for other leet code problems.

public String serialize(TreeNode root) {
    LinkedList<TreeNode> queue = new LinkedList<>();
    queue.addLast(root);
    StringBuilder sBuilder = new StringBuilder();
    while (!queue.isEmpty()) {
        TreeNode node = queue.removeFirst();
        if (node == null) {
            sBuilder.append("null,");
        } else {
            sBuilder.append(node.val + ",");
            queue.addLast(node.left);
            queue.addLast(node.right);
        }
    }
    return "[" + sBuilder.substring(0, sBuilder.length() - 1) + "]";
}

public TreeNode deserialize(String data) {
    if (data == null || data.length() < 2) {
        throw new IllegalArgumentException("Invalid syntax for " + data);
    }
    String trimmed;
    if (data.charAt(0) == '[' && data.charAt(data.length() - 1) == ']') {
        trimmed = data.substring(1, data.length() - 1);
    } else {
        throw new IllegalArgumentException("Invalid syntax for " + data);
    }
    String[] elements = trimmed.split(",");
    TreeNode[] nodes = new TreeNode[elements.length];
    for (int i = 0; i < elements.length; i++) {
        if (elements[i].equals("null")) {
            continue;
        }
        try {
            int val = Integer.parseInt(elements[i]);
            nodes[i] = new TreeNode(val);
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException("Invalid syntax for " + data);
        }
    }
    TreeNode root = nodes[0];
    LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
    queue.addLast(root);
    for (int i = 1; i < nodes.length; i++) {
        TreeNode node;
        try {
            node = queue.getFirst();
        } catch (NoSuchElementException e) {
            throw new IllegalArgumentException("Invalid binary tree");
        }
        if ((i & 1) == 1) {
            node.left = nodes[i];
        } else {
            node.right = nodes[i];
            queue.removeFirst();
        }
        if (nodes[i] != null) {
            queue.addLast(nodes[i]);
        }
    }
    return root;
}
