import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        int[] result = new int[2];

        for (int i = 0; i < nums.length; ++i) {
            int diff = target - nums[i];

            if (map.containsKey(diff)) {
                result[0] = map.get(diff);
                result[1] = i;
                break;
            } else {
                map.put(nums[i], i);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        int[] result = sol.twoSum(nums, target);

        System.out.println(Arrays.toString(result));
    }
}
