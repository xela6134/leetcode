package longestPalindromicSubstring;

class Solution {
    public static String longestPalindrome(String s) {
		String longestPalindrome = "";
		int maxLength = 0;
		
		for (int i = 0; i < s.length(); i++) {
			int left = i;
			int right = i;
			while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
				if (right - left + 1 > maxLength) {
					maxLength = right - left + 1;
					longestPalindrome = s.substring(left, right + 1);
				}
				left--;
				right++;
			}

			left = i;
			right = i + 1;
			while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
				if (right - left + 1 > maxLength) {
					maxLength = right - left + 1;
					longestPalindrome = s.substring(left, right + 1);
				}
				left--;
				right++;
			}
		}
        
		return longestPalindrome;
    }

	public static void main(String[] args) {
		String input = "babad";
		String longestPalindrome = longestPalindrome(input);
		System.out.println(longestPalindrome);
	}
}