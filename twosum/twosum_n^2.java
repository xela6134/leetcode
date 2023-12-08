import java.util.Arrays;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int length = nums.length;
        int[] originalNums = new int[length];
        System.arraycopy(nums, 0, originalNums, 0, length);
        
        Arrays.sort(nums);
        int a = 0, b = 0;
        for (int i = 0; i < length; i++) {
            int index = Arrays.binarySearch(nums, i + 1, length, target - nums[i]);
            if (index >= 0) {
                a = nums[i];
                b = nums[index];
            }
        }

        int index1 = -1, index2 = -1, prevIndex = -1;
        for (int i = 0; i < length; i++) {
            if (originalNums[i] == a) {
                index1 = i;
                prevIndex = i;
            }
        }

        for (int i = 0; i < length; i++) {
            if (originalNums[i] == b && prevIndex != i) {
                index2 = i;
            }
        }

        return new int[] {index1, index2};
    }
}