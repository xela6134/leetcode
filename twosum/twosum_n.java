import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> numMap = new HashMap<>();
            
        for (int i = 0; i < nums.length; i++) {
            int subtract = target - nums[i];
            if (numMap.containsKey(subtract)) {
                return new int[] {numMap.get(subtract), i};
            } else {
                numMap.put(nums[i], i);
            }
        }
        return null;
    }
}