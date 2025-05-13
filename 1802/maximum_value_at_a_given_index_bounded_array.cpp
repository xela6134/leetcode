#include <iostream>

long long calcSum(long long peak, long long length) {
    if (peak > length) {
        long long high = peak - 1;
        long long low = peak - length;
        return (high + low) * length / 2;
    } else {
        long long decreasingSum = (peak - 1) * peak / 2;
        return decreasingSum + (length - (peak - 1));
    }
}

// 5 6 7

bool isValid(int mid, int n, int index, int maxSum) {
    long long leftSum = calcSum(mid, index);
    long long rightSum = calcSum(mid, n - index - 1);
    long long total = leftSum + rightSum + mid;

    // std::cout << "For mid: " << mid << ", Left: " << leftSum << ", Right: " << rightSum << ", Total: " << total << std::endl;

    return total <= maxSum;
}

int maxValue(int n, int index, int maxSum) {
    int low = 1;
    int high = maxSum;
    int result = 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isValid(mid, n, index, maxSum)) {
            // std::cout << mid << " works" << std::endl;
            result = mid;
            low = mid + 1;
        } else {
            // std::cout << mid << " doesn't work" << std::endl;
            high = mid - 1;
        }
    }

    return result;
}

int main() {

}
