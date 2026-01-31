// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/?envType=problem-list-v2&envId=prefix-sum

class Solution {
    TreeMap<Integer, Integer> map;
    int[][] arrays;
    int sum;
    Random rnd = new Random();

    public Solution(int[][] rects) {
        arrays = rects;
        map = new TreeMap<>();
        sum = 0;

        for(int i = 0; i < rects.length; i ++) {
            int[] rect = rects[i];
            sum += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);

            map.put(sum, i);
        }
    }
    
    public int[] pick() {
        int c = map.ceilingKey(rnd.nextInt(sum) + 1);

        return pickInRect(arrays[map.get(c)]);
    }

    private int[] pickInRect(int[] rect) {
        int left = rect[0], right = rect[2], bot = rect[1], top = rect[3];

        return new int[]{left + rnd.nextInt(right - left + 1), bot + rnd.nextInt(top - bot + 1)};
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * int[] param_1 = obj.pick();
 */

/**
This solution solves the problem of picking a random integer point uniformly from multiple non-overlapping rectangles. The key idea is to treat all points across all rectangles as one continuous pool and then map a random choice back to the correct rectangle.

During initialization, the solution computes the number of integer points in each rectangle using
(x2 - x1 + 1) * (y2 - y1 + 1). A prefix sum of these counts is maintained using a TreeMap, where each key represents the cumulative number of points up to a rectangle, and the value stores the rectangle’s index. The final prefix sum (sum) represents the total number of valid points across all rectangles.

When pick() is called, a random integer r is generated in the range [1, sum]. Using TreeMap.ceilingKey(r), the algorithm efficiently determines which rectangle contains the r-th point in the conceptual flattened list of all points. This ensures that rectangles with larger areas are chosen more often, maintaining correct probability distribution.

After selecting the rectangle, a random point is generated uniformly within its bounds by independently choosing random x and y coordinates. This two-step process guarantees that every point across all rectangles has equal probability of being selected, while keeping the runtime efficient.
**/
