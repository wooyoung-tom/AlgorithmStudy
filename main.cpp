#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <cmath>

using namespace std;

// 수의 개수 N(1 ≤ N ≤ 500,000)
int N;

// 산술평균 : N개의 수들의 합을 N으로 나눈 값
long long mean(const vector<int> &v) {
    long long sum = 0;
    for (int i : v) sum += i;
    double mean = (double) sum / v.size();
    return round(mean);
}
// 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
int middle(vector<int> v) {
    int mid = 0;
    sort(v.begin(), v.end());
    if (v.size() % 2 == 0) {
        mid = (int) v.size() / 2 + 1;
    } else {
        mid = (int) v.size() / 2;
    }
    return v[mid];
}
// 최빈값 : N개의 수들 중 가장 많이 나타나는 값
int most(const vector<int> &v) {

}
// 범위 : N개의 수들 중 최댓값과 최솟값의 차이
int range(const vector<int> &v) {
    int minNum = *min_element(v.begin(), v.end());
    int maxNum = *max_element(v.begin(), v.end());
    return maxNum - minNum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int tmp = 0;
        cin >> tmp;
        nums.push_back(tmp);
    }

    // 산술 평균
    cout << mean(nums) << "\n";
    // 중앙값
    cout << middle(nums) << "\n";
    // 최빈값
    cout << most(nums) << "\n";
    // 범위
    cout << range(nums) << "\n";
}