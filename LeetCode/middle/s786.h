#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::sort;

class Solution {
public:
    struct Ratio {
        int fenzi;
        int fenmu;
        double fraction;
    };
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<Ratio> nums;
        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                Ratio r = { arr[i],arr[j],static_cast<double>(arr[i]) / arr[j] };
                nums.push_back(r);
            }
        }
        sort(nums.begin(), nums.end(), compareRatio);
        vector<int> res{ nums[k - 1].fenzi,nums[k - 1].fenmu };
        return res;
    }
    static bool compareRatio(const Ratio& a, const Ratio& b) {
        return (a.fraction < b.fraction);
    }

    static void test() {
        Solution sol;
        vector<int> arr{1,2,3,5};
        auto res = sol.kthSmallestPrimeFraction(arr,3);
        for (auto n : res) {
            std::cout << n << ",";
        }
    }
};