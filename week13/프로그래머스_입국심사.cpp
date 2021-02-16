//
// Created by 최우영 on 2021/02/16.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    // left 1로 초기화, right 가장 큰 수 * n 으로 초기화
    ll left = 1;
    ll right = (ll) *max_element(times.begin(), times.end()) * n;

    while (left <= right) {
        ll mid = (left + right) / 2;
        ll res = 0;

        // mid 에서 해당 시간을 나누면 그 시간에 가능한 사람 수가 된다.
        // 그렇게 모든 시간을 나누어주고 모두 더한 값을 구한다.
        for (int i = 0; i < times.size(); ++i) {
            res += (ll) mid / times[i];
        }

        // n 보다 작으면 n 명을 처리하지 못했다는 뜻이 된다.
        // n 보다 크면 n 명을 처리하였다는 뜻이 된다.
        if (res < n) left = mid + 1;
        else {
            right = mid - 1;
            answer = mid;
        }
    }

    return answer;
}