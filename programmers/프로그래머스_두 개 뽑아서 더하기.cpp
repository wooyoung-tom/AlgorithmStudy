//
// Created by 최우영 on 2020/10/26.
//

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    set<int> setNumbers;

    for (int i = 0; i < numbers.size(); ++i) {
        for (int j = i + 1; j < numbers.size(); ++j) {
            int sum = numbers[i] + numbers[j];
            setNumbers.insert(sum);
        }
    }

    vector<int> temp(setNumbers.begin(), setNumbers.end());

    answer.assign(temp.begin(), temp.end());

    return answer;
}