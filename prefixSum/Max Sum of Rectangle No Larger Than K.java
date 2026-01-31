// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/?envType=problem-list-v2&envId=prefix-sum
class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int m = matrix.length, n = matrix[0].length;
        int ans = Integer.MIN_VALUE;

        for(int r1 = 0; r1 < m; r1 ++) {
            int[] arr = new int[n];
            for(int r2 = r1; r2 < m; r2 ++) {
                // prefix sum row wise;
                for(int c = 0; c < n; c ++) arr[c] += matrix[r2][c];
                // find the max sum;
                ans = Math.max(ans, maxSumSubArray(arr, n, k));
            }
        }

        return ans;
    }

    int maxSumSubArray(int[] arr, int n, int k) {
        TreeSet<Integer> bst = new TreeSet<>();
        bst.add(0);
        int right = 0;
        int ans = Integer.MIN_VALUE;
        for(int i = 0; i < n; i ++) {
            right += arr[i];

            Integer left = bst.ceiling(right - k);
            if(left != null) {
                ans = Math.max(ans, right - left);
            }
            bst.add(right);
        }
        return ans;
    }
}

/**
This solution finds the maximum sum submatrix whose sum does not exceed k by reducing the 2D problem into multiple 1D subarray problems. The approach fixes two row boundaries at a time and compresses the rows between them into a single array that represents column-wise sums. For each such compressed array, the task becomes finding the maximum subarray sum that is ≤ k.

To efficiently solve the 1D subproblem, the algorithm uses prefix sums combined with a TreeSet. As it iterates through the array, it maintains a running prefix sum and stores all previously seen prefix sums in a sorted set. For the current prefix sum right, it searches for the smallest prefix sum left such that left ≥ right − k. This guarantees that the subarray sum right − left is valid (≤ k) and as large as possible. The TreeSet enables this lookup in logarithmic time.

By iterating over all possible pairs of row boundaries and applying this optimized 1D solution, the algorithm examines all valid submatrices while staying efficient. The overall time complexity is O(m² · n log n), making it suitable for medium-sized matrices and a common interview pattern for constrained 2D maximum subarray problems.
**/
