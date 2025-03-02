#include <vector>
#include <string>
#include <iostream>

int compress(std::vector<char>& chars) {
    int index = 0;

    // Pseudocode
    // 
    // When iterating:
    // - Keep track of curr_character, and start_index of that character
    // 
    // - If char_count == 1, don't do anything
    // - If char_count >= 1, ++char_count, ++end_index
    // - When next char is different OR end of string:
    //     - Start writing from start_index + 1
    //     - Fill remaining chars until end_index as ' '
    // - After while loop finished, remove all ' 's using std::remove and erase

    while (index < chars.size()) {
        char curr_character = chars[index];
        int char_count = 1;

        // 1. Finding the occurrences for each character
        int start_index = index;
        int end_index = index + 1;
        while (end_index < chars.size() and chars[end_index] == curr_character) {
            ++char_count;
            ++end_index;
        }

        index = end_index;
        // std::cout << curr_character << ": " << char_count << std::endl;
        // std::cout << "S: " << start_index << ", E: " << end_index << std::endl;

        // 2. Replace with Number

        // Continue if there is no chars to replace
        if (char_count == 1) continue;

        // Start writing from start_index + 1
        std::string count_string = std::to_string(char_count);
        for (int i = 0; i < count_string.size(); ++i) {
            ++start_index;
            chars[start_index] = count_string[i];
        }

        // 3. Remove junk chars
        for (int i = start_index + 1; i < end_index; ++i) {
            chars[i] = ' ';
        }
    }

    // 4. Remove all spaces
    chars.erase(std::remove(chars.begin(), chars.end(), ' '), chars.end());
    return chars.size();
}

void print_chars(std::vector<char>& chars) {
    for (const char& c : chars) {
        std::cout << c;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<char> chars1 = {'a','a','b','b','c','c','c'};
    std::cout << compress(chars1) << ": ";
    print_chars(chars1);

    std::vector<char> chars2 = {'a'};
    std::cout << compress(chars2) << ": ";
    print_chars(chars2);

    std::vector<char> chars3 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    std::cout << compress(chars3) << ": ";
    print_chars(chars3);

    std::vector<char> chars4 = {'a','b','b','b','b','b','b','b','b','b','b','b','b','c','c','c','c'};
    std::cout << compress(chars4) << ": ";
    print_chars(chars4);
}
