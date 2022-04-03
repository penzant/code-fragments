#include <bits/stdc++.h>
using namespace std;

bool comp_binary_search(int v, int k) {
    if (v == k) return true;
    else return false;
}

bool comp_lower_bound(int v, int k) {
    if (v >= k) return true;
    else return false;
}

bool comp_upper_bound(int v, int k) {
    if (v > k) return true;
    else return false;
}

int binary_search(vector<int> ary, int k, string method) {
    bool (*comp)(int, int);
    if (method == "binary_search") {
        comp = &comp_binary_search;
    } else if (method == "lower_bound") {
        comp = &comp_lower_bound;
    } else if (method == "upper_bound") {
        comp = &comp_upper_bound;
    }
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

void call_functions(vector<int> ary, int key, string method) {
    cout << method  << " for " << key << " is index = " << binary_search(ary, key, method) << endl;
}

int main() {
    vector<int> test_array{1,2,5,5,7,10,22};
    cout << "array = 1, 2, 5, 5, 7, 10, 22" << endl;
    for (string method: {"binary_search", "lower_bound", "upper_bound"}) {
        cout << endl;
        for (int key : {5, 6, 7, 10, 12}) {
            call_functions(test_array, key, method);
        }
    }
}
