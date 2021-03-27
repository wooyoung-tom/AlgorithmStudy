//
// Created by djdj7 on 2020-05-18.
//

/*
 *  TODO 스택/큐 문제...?
 *   다시 해봐야 할 것 같음.
 *   스택을 사용해서 어떻게 푸는가?
 *   더 시간을 줄일수 있는가?
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int count = 0;

    for (int i = 0; i < prices.size(); ++i) {
        int current_price = prices[i];
        for (int j = i+1; j < prices.size(); ++j) {
            if (current_price <= prices[j]) {
                count++;
            } else {
                count++;
                break;
            }
        }
        answer.push_back(count);
        count = 0;
    }

    return answer;
}

int main() {
    vector<int> prices = {1, 2, 3, 2, 3};
    solution(prices);
}