/* package longestsubstring;

class Solution {
    public static int lengthOfLongestSubstring(String s) {
        int maxlen = 0;
        String finalString = null;

        for (int i = 0; i < s.length(); i++) {
            String temp = String.valueOf(s.charAt(i));
            String fin = String.valueOf(s.charAt(i));
            for (int j = i + 1; j < s.length(); j++) {
                if (temp.indexOf(s.charAt(j)) == -1) {
                    // char at j does not exist in temp
                    temp = temp + String.valueOf(s.charAt(j));
                    fin = temp;
                } else {
                    fin = temp;
                    break;
                }
            }

            if (fin.length() > maxlen) {
                maxlen = fin.length();
                finalString = fin;
            }
        }
        
        System.out.println(finalString);
        return maxlen;
    }

    public static void main(String[] args) {
        String s = "au";
        int len = lengthOfLongestSubstring(s);
        System.out.println(len);
    }
} */