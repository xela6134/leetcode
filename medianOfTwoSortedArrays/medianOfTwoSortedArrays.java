package medianOfTwoSortedArrays;

import java.util.ArrayList;
import java.util.List;

class Solution {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        List<Integer> intList = new ArrayList<>();

        int index1 = 0;
        int index2 = 0;

        int nums1max = nums1.length;
        int nums2max = nums2.length;
        
        while (index1 != nums1max || index2 != nums2max) {
            if (index1 == nums1max && index2 != nums2max) {
                intList.add(nums2[index2]);
                index2++;
                continue;
            }
            
            if (index2 == nums2max && index1 != nums1max) {
                intList.add(nums1[index1]);
                index1++;
                continue;
            }

            if (nums1[index1] > nums2[index2]) {
                intList.add(nums2[index2]);
                index2++;
            } else {
                intList.add(nums1[index1]);
                index1++;
            }
        }

        int listLen = intList.size();
        double returnValue;
        if (listLen % 2 == 1) {
            returnValue = intList.get((listLen) / 2);
        } else {
            int returnIndex = listLen / 2;
            double val1 = (double) intList.get(returnIndex);
            double val2 = (double) intList.get(returnIndex - 1);
            returnValue = (val1 + val2) / 2;
        }

        return returnValue;
    }

    public static void main(String args[]) {
        int[] nums1 = {1, 2};
        int[] nums2 = {3, 4};

        double value = findMedianSortedArrays(nums1, nums2);
        System.out.println(value);
    } 
}
