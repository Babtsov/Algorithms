public String simplifyPath(String path) {
    String[] parts = path.split("/");
    LinkedList<String> simplifiedPath = new LinkedList<>();
    for (String part : parts) {
        if (part.equals("") || part.equals(".")) {
            continue;
        } else if (part.equals("..") && !simplifiedPath.isEmpty()) {
            simplifiedPath.removeLast();
        } else if (!part.equals("..")) {
            simplifiedPath.addLast(part);
        }
    }
    StringBuilder sBuilder = new StringBuilder();
    for (String part : simplifiedPath) {
        sBuilder.append("/" + part);
    }
    return simplifiedPath.isEmpty()? "/" : sBuilder.toString();
}
