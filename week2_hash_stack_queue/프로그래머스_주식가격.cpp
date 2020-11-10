//
// Created by 최우영 on 2020/11/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for (int i = 0; i < prices.size(); ++i) {
        int currentPrice = prices[i];
        int counter = 0;

        // 마지막 원소는 다음이 없기 때문에 0초
        if (i == prices.size() - 1) {
            answer.push_back(counter);
            break;
        }

        // 현재 원소보다 한칸 앞에서 시작
        for (int j = i + 1; j < prices.size(); ++j) {
            int targetPrice = prices[j];
            // 현재 원소보다 크거나 같으면 counter++
            if (currentPrice <= targetPrice) {
                counter++;
            }
                // 현재 원소보다 작으면 counter 하나 올리고 break
            else {
                counter++;
                break;
            }
        }
        answer.push_back(counter);
    }

    return answer;
}