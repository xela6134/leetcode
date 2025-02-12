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
    int size = matrix.size();
    std::vector<std::vector<int>> new_matrix(size, std::vector<int>(size, 0));

    // (0,0) (0,1) (0,2)
    // (1,0) (1,1) (1,2)
    // (2,0) (2,1) (2,2)

    // (2,0) (1,0) (0,0)
    // (2,1) (1,1) (0,1)
    // (2,2) (1,2) (0,2)

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            new_matrix[j][size - 1 - i] = matrix[i][j];
        }
    }

    matrix = new_matrix;
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
