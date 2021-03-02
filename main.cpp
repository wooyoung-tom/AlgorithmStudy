#include <iostream>

#define MAX 1000001

using namespace std;

// (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)
int N, M;
int tree[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> tree[i];
    }


}