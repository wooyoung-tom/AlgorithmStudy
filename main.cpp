#include <iostream>

#define MAX 501

using namespace std;

// M과 N은 각각 500이하의 자연수
int M, N;
int map[MAX][MAX];
int dp[MAX][MAX];

void solve() {
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> map[i][j];
        }
    }

    solve();

    cout << dp[M][N] << "\n";
}