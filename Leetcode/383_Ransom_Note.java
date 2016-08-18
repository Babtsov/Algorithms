public boolean canConstruct(String ransomNote, String magazine) {
    HashMap<Character, Integer> letterCounts = new HashMap<>();
    for (int i = 0; i < magazine.length(); i++) {
        char c = magazine.charAt(i);
        int count = letterCounts.containsKey(c) ? letterCounts.get(c) + 1 : 1;
        letterCounts.put(c, count);
    }
    for (int i = 0; i < ransomNote.length(); i++) {
        char c = ransomNote.charAt(i);
        int count = letterCounts.containsKey(c) ? letterCounts.get(c) - 1 : -1;
        if (count < 0) {
            return false;
        }
        letterCounts.put(c, count);
    }
    return true;
}
