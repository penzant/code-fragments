#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> ary, int k, bool (*comp)(int, int)) {
    int left = -1, right = ary.size();
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (comp(ary[mid], k)) right = mid;
        else left = mid;
    }
    // left is the max position that doesn't satisfy the condition
    // right is the min position that satisfies the condition
    return right;
}

int main() {
    vector<int> test_array {1, 2, 5, 5, 7, 10, 22};
    cout << "array = 1, 2, 5, 5, 7, 10, 22" << endl;
    vector<pair<string, bool (*)(int, int)> > methods {
        make_pair("binary_search", [](int v, int k) { return v > k; }),
        make_pair("lower_bound", [](int v, int k) { return v == k; }),
        make_pair("upper_bound", [](int v, int k) { return v >= k; }),
    };
    for (auto p: methods) {
        cout << endl;
        for (int key : {5, 6, 7, 10, 12}) {
            cout << p.first  << " for " << key << " is index = "
                 << binary_search(test_array, key, p.second) << endl;
        }
    }
}
