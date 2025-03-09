#include <iostream>
#include <string>
#include <queue>

auto predictPartyVictory(std::string senate) -> std::string {
    std::queue<int> radiants;
    std::queue<int> dires;

    for (int i = 0; i < senate.size(); ++i) {
        if (senate[i] == 'R') radiants.push(i);
        else dires.push(i);
    }

    int offset = senate.size();

    // std::cout << radiants.size() << ", " << dires.size() << std::endl;

    while ((not radiants.empty()) and (not dires.empty())) {
        int curr_radiant = radiants.front();
        int curr_dire = dires.front();

        // std::cout << curr_radiant << ", " << curr_dire << std::endl;

        radiants.pop();
        dires.pop();

        if (curr_radiant < curr_dire) {
            radiants.push(offset);
        } else {
            dires.push(offset);
        }
        ++offset;
    }

    return radiants.empty() ? "Dires" : "Radiants";
}

int main() {
    std::cout << predictPartyVictory("RRDDD") << std::endl;
    std::cout << predictPartyVictory("RD") << std::endl;
    std::cout << predictPartyVictory("RDD") << std::endl;
    std::cout << predictPartyVictory("RRR") << std::endl;
}
