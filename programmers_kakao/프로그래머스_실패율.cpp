//
// Created by djdj7 on 2020-05-15.
//

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct {
    int success;
    int total;
    float rate;
} STAGE_INFO;

bool cmp(const pair<int, float> &a, const pair<int, float> &b) {
    if (a.second > b.second) {
        return true;
    } else if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return false;
    }
}

vector<int> solution(int N, vector<int> stages) {

    vector<int> answer;
    vector<pair<int, float>> rate_v;
    map<int, STAGE_INFO> stage_map;

    for (int i = 0; i < stages.size(); ++i) {
        for (int j = 1; j < stages[i]; ++j) {
            stage_map[j].success++;
            stage_map[j].total++;
        }
        stage_map[stages[i]].total++;
    }

    for (int k = 1; k <= N; ++k) {
        if (stage_map[k].total == 0) {
            stage_map[k].rate = 0;
            rate_v.push_back(make_pair(k, stage_map[k].rate));
        } else {
            stage_map[k].rate = (float) (stage_map[k].total - stage_map[k].success) / stage_map[k].total;
            rate_v.push_back(make_pair(k, stage_map[k].rate));
        }
    }

    sort(rate_v.begin(), rate_v.end(), cmp);

    for (int l = 0; l < rate_v.size(); ++l) {
        answer.push_back(rate_v[l].first);
        cout << rate_v[l].first << " ";
    }
    return answer;
}

int main() {
    vector<int> stages = {2, 1, 2, 4, 2, 4, 3, 3};
    solution(5, stages);
}