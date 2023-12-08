import java.util.Arrays;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int length = nums.length;
        Arrays.sort(nums);
        for (int i = 0; i < length; i++) {
            int[] newNums = Arrays.copyOfRange(nums, i, length);
            int index = Arrays.binarySearch(newNums, target - nums[i]);
            if (index != -1 * (newNums.length + 1)) {
                int[] ans = {i, index};
                return ans;
            }
        }
        return null;
    }
}