package cpduels;

public class qaq {
    public static int howManyQAQs(String input) {
        // true: left moves to the right in next sequence
        // false: right moves to the left in next sequence

        int total = 0;
        int len = input.length();

        int leftIndex = 0;
        while (leftIndex < len) {

            if (input.charAt(leftIndex) != 'Q') {
                leftIndex++;
                continue;
            }

            for (int rightIndex = leftIndex + 2; rightIndex < len; rightIndex++) {
                if (input.charAt(rightIndex) == 'Q') {
                    String substring = input.substring(leftIndex + 1, rightIndex);
                    
                    System.out.println("Printing from index " + leftIndex + " to " + rightIndex + ", substring is " + substring);

                    int numOfAs = (int) substring.chars().filter(ch -> ch == 'A').count();
                    total += numOfAs;
                }
            }
            leftIndex++;
        }
        return total;
    }

    public static void main(String[] args) {
        String input = "QAQAQYSYIOIWIN";
        int num = howManyQAQs(input);
        System.out.println(num);
    }
}
