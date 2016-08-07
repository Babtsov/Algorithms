public class Solution {
    private static class BackTrack {
        private int[] candidates;
        private List<List<Integer>> solutions;
        
        public BackTrack(int[] candidates, int target) {
            this.candidates = candidates;
            solutions = new ArrayList<List<Integer>>();
            generateSolutions(target, 0, new Stack<Integer>());
        }
        
        public List<List<Integer>> getSolutions() {
            return solutions;
        }
        
        private void generateSolutions(int target, int index, Stack<Integer> sequence) {
            if (target == 0) {
                solutions.add(new ArrayList<>(sequence));
            } else if (target > 0) {
                for (int i = index; i < candidates.length && candidates[i] <= target; i++) {
                    sequence.push(candidates[i]);
                    generateSolutions(target - candidates[i], i,sequence);
                    sequence.pop();
                }
            }
        }
    }
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        return new BackTrack(candidates,target).getSolutions();
    }
}
