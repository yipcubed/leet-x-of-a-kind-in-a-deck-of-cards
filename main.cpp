#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    bool alldivisible(map<int,int>& seen, int num) {
        for (auto& p : seen) {
            if (p.second % num != 0)
                return false;
        }
        return true;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        int small = INT_MAX;
        map<int, int> seen;
        for (auto& i : deck) {
            ++seen[i];
        }
        for (auto& p : seen) {
            small = min(small,p.second);
        }
        if (small == 1) return false;
        for (int i = 2; i <= small; ++i) {
            if (alldivisible(seen, i))
                return true;
        }
        return false;
    }
};

void test1() {
    vector<int> v1{1,2,3,4,4,3,2,1};

    cout << "1 ? " << Solution().hasGroupsSizeX(v1) << endl;

    vector<int> v2{1,1};

    cout << "1 ? " << Solution().hasGroupsSizeX(v2) << endl;

    vector<int> v3{1,1,1,2,2,2,3,3};

    cout << "0 ? " << Solution().hasGroupsSizeX(v3) << endl;
}

void test2() {

}

void test3() {

}