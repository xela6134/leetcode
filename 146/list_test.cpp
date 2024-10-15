#include <list>
#include <iostream>
#include <utility>
#include <algorithm>

int main() {
    std::list<int> myList = {1, 2, 3, 4, 5};

    auto it = std::find(myList.begin(), myList.end(), 3);

    if (it != myList.end()) {
        myList.splice(myList.begin(), myList, it);
    }

    for (const int& val : myList) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
