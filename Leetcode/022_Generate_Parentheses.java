public void helper(int charsLeft, StringBuilder b, int balance, List<String> solution) {
    if (balance < 0 || balance > charsLeft) return; // we have more ')' than '(' or too many '(', so backtrack...
    if (charsLeft == 0) {
        solution.add(b.toString());
        return;
    }
    b.append("(");
    helper(charsLeft - 1, b, balance + 1, solution);
    b.setLength(b.length() - 1);
    b.append(")");
    helper(charsLeft - 1, b, balance - 1, solution);
    b.setLength(b.length() - 1);
}
public List<String> generateParenthesis(int n) {
    List<String> solution = new ArrayList<>();
    helper(2*n, new StringBuilder(), 0, solution);
    return solution;
}
