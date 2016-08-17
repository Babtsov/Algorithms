public boolean isIsomorphic(String s, String t) {
    if (s == null || t == null || s.length() != t.length()) {
        return false;
    }
    HashMap<Character, Character> map = new HashMap<>();
    HashSet<Character> values = new HashSet<>();
    for (int i = 0; i < s.length(); i++) {
        char l = s.charAt(i), r = t.charAt(i);
        if (map.containsKey(l)) {
            if (map.get(l) != r) {
                return false;
            }
        } else if (values.contains(r)) {
            return false;
        } else {
            map.put(l, r);
            values.add(r);
        }
    }
    return true;
}
