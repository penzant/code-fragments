#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> ary, int k, bool (*comp)(int, int)) {
    // left is the max position that doesn't satisfy the condition
    // right is the min position that satisfies the condition
    int left = -1, right = ary.size();
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (comp(ary[mid], k)) right = mid;
        else left = mid;
    }
    return right;
}

void test_binary_search(string method, bool (*func)(int, int)) {
    vector<int> test_array {1, 2, 5, 5, 7, 10, 22};
    cout << "array = 1, 2, 5, 5, 7, 10, 22" << endl;
    for (int key : {5, 6, 7, 10, 12})
        cout << method  << " for " << key << " is index = "
             << binary_search(test_array, key, func) << endl;
}

int main() {
    test_binary_search("binary_search", [](int v, int k) { return v == k; });
    test_binary_search("lower_bound", [](int v, int k) { return v >= k; });
    test_binary_search("upper_bound", [](int v, int k) { return v > k; });
}
