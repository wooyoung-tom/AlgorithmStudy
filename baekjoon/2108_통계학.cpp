//
// Created by 최우영 on 2021/05/05.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 수의 개수 N(1 ≤ N ≤ 500,000)
int N;
vector<int> nums;

// 산술평균 : N개의 수들의 합을 N으로 나눈 값
long mean() {
    double sum = 0;
    for (int i : nums) sum += i;

    double result = sum / N;

    return lround(result);
}

// 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
int middle() {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

bool compare(const pair<int, int> &first, const pair<int, int> &second) {
    if (first.second > second.second) return true;
    else if (first.second == second.second) {
        if (first.first < second.first) return true;
        else return false;
    } else return false;
}

// 최빈값 : N개의 수들 중 가장 많이 나타나는 값
int most() {
    // index 와 횟수 넣어놓을 container
    vector<pair<int, int>> frequency(8001);

    // 숫자에 해당하는 index 찾아서 count
    // 음수가 -4000까지 내려가므로 첫 인덱스는 0이 되려면 4000 더해주어야 함
    for (auto i: nums) {
        frequency[i + 4000].first = i + 4000;
        frequency[i + 4000].second++;
    }

    sort(frequency.begin(), frequency.end(), compare);

    if (frequency[0].second == frequency[1].second) {
        return frequency[1].first - 4000;
    } else return frequency[0].first - 4000;
}

// 범위 : N개의 수들 중 최댓값과 최솟값의 차이
int range() {
    int minNum = *min_element(nums.begin(), nums.end());
    int maxNum = *max_element(nums.begin(), nums.end());
    return maxNum - minNum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int tmp = 0;
        cin >> tmp;
        nums.push_back(tmp);
    }

    // 산술 평균
    cout << mean() << "\n";
    // 중앙값
    cout << middle() << "\n";
    // 최빈값
    cout << most() << "\n";
    // 범위
    cout << range() << "\n";
}