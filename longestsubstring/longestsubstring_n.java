package longestsubstring;

import java.util.HashSet;
import java.util.Set;

class Solution {
    public static int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxLength = 0;
        Set<Character> charSet = new HashSet<>();
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (!charSet.contains(s.charAt(right))) {
                charSet.add(s.charAt(right));
                maxLength = Math.max(maxLength, right - left + 1);
            } else {
                while (charSet.contains(s.charAt(right))) {
                    charSet.remove(s.charAt(left));
                    left++;
                }
                charSet.add(s.charAt(right));
            }
        }
        
        return maxLength;
    }

    public static void main(String[] args) {
        String s = "abcabcab";
        int len = lengthOfLongestSubstring(s);
        System.out.println(len);
    }
}
