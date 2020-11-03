//
// Created by 최우영 on 2020/11/01.
//

#include <vector>
#include <set>

using namespace std;

int order(const vector<int>& russian, const vector<int>& korean) {
    int n = russian.size();
    int wins = 0;

    // 아직 남아있는 선수들의 rating
    multiset<int> ratings(korean.begin(), korean.end());

    for (int rus = 0; rus < n; ++rus) {
        // 가장 레이팅이 높은 한국 선수가 이길수 없는 경우
        // 가장 레이팅이 낮은 선수와 경기 시킨다.
        if (*ratings.rbegin() < russian[rus]) {
            ratings.erase(ratings.begin());
        }

        // 이 외의 경우 이길 수 있는 선수 중 가장 레이팅이 낮은 선수와 경기시킨다.
        else {
            ratings.erase(ratings.lower_bound(russian[rus]));
            ++wins;
        }
    }

    return wins;
}