#include <iostream>

int pick = 6;

int guess(int num) {
    if (num > pick) return -1;
    if (num < pick) return 1;
    return 0;
}

int guessNumber(int n) {
    // wtf is this question description
    int left = 1;
    int right = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int res = guess(mid);

        if (res == 0) return mid;
        else if (res < 0) right = mid - 1;
        else left = mid + 1;
    }

    return -1;
}

int main() {

}
