#include <vector>
#include <iostream>

// void rotate(std::vector<std::vector<int>>& matrix) {
//     // if
//     // 1 2 3
//     // 4 5 6
//     // 7 8 9

//     // read 1 -> 2 -> 3
//     // then paste it as
//     // ? ? 1      ? 4 1
//     // ? ? 2  ->  ? 5 2
//     // ? ? 3      ? 6 3

//     int size = static_cast<int>(matrix.size());

//     std::vector<std::vector<int>> updated(size, std::vector<int>(size, 0));

//     for (int i = 0; i < size; ++i) {
//         for (int j = 0; j < size; ++j) {
//             updated[j][size - 1 - i] = matrix[i][j];
//         }
//     }

//     matrix = updated;
// }

void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();

    // Step 1: Transpose
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; ++i) {
        std::reverse(matrix[i].begin(), matrix[i].end());
    }
}

void print_matrix(std::vector<std::vector<int>>& matrix) {
    for (auto it1 = matrix.begin(); it1 != matrix.end(); ++it1) {
        auto line = *it1;
        for (auto it2 = line.begin(); it2 != line.end(); ++it2) {
            std::cout << *it2 << " ";
        }
        std::cout << std::endl;
    }
}

auto main() -> int {
    std::vector<std::vector<int>> matrix1 = {{1,2,3}, {4,5,6}, {7,8,9}};
    std::vector<std::vector<int>> matrix2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotate(matrix1);
    rotate(matrix2);    
    print_matrix(matrix1);
    print_matrix(matrix2);
}
