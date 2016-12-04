public void helper(int charsLeft, StringBuilder b, int balance, List<String> solution) {
    if (balance < 0) return; // we have more ')' than '(', so backtrack...
    if (charsLeft == 0) {
        if (balance == 0) solution.add(b.toString());
        return;
    }
    b.append("("); // push '(' 
    helper(charsLeft - 1, b, balance + 1, solution);
    b.setLength(b.length() - 1); // pop '('
    b.append(")"); // push ')'
    helper(charsLeft - 1, b, balance - 1, solution);
    b.setLength(b.length() - 1); // pop ')'
}
public List<String> generateParenthesis(int n) {
    List<String> solution = new ArrayList<>();
    helper(2*n, new StringBuilder(), 0, solution);
    return solution;
}
