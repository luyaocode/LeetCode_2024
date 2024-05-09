#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0;
        int currCapacity = capacity;
        steps += 1;
        if (plants.size() == 0) {
            return 0;
        }
        currCapacity -= plants[0];
        for (int i = 0; i < plants.size()-1; i++) {
            auto nextNeed = plants[i + 1];
            if (currCapacity >= nextNeed) {
                steps += 1;
                currCapacity -= nextNeed;
            }
            else {
                currCapacity = capacity - nextNeed;
                steps += (2 * (i + 1) + 1);
            }
        }
        return steps;
    }

    static void test() {
        vector<int> plants{ 2,2,3,3 };
        int capacity = 5;
        Solution sol;
        auto steps= sol.wateringPlants(plants, capacity);
        std::cout << steps;
    }
};
