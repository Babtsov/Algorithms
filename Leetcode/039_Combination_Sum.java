public class Solution {
    private static class BackTrack {
        private int[] candidates;
        private List<List<Integer>> solutions;
        private int target;
        
        public BackTrack(int[] candidates, int target) {
            this.candidates = candidates;
            this.target = target;
            solutions = new ArrayList<List<Integer>>();
            generateSolutions(0, 0, new Stack<Integer>());
        }
        
        public List<List<Integer>> getSolutions() {
            return solutions;
        }
        
        private void generateSolutions(int sum, int index, Stack<Integer> sequence) {
            if (sum == target) {
                ArrayList<Integer> list = new ArrayList<>();
                list.addAll(sequence);
                solutions.add(list);
            } else if (sum < target) {
                for (int i = index; i < candidates.length; i++) {
                    sequence.push(candidates[i]);
                    generateSolutions(sum + candidates[i], i,sequence);
                    sequence.pop();
                }
            }
        }
        
    }
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        return new BackTrack(candidates,target).getSolutions();
    }
}
