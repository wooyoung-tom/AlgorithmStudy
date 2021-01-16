//
// Created by 최우영 on 2021/01/09.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cnt;
bool isVisited[51];
queue<string> q;

bool isConvertible(const string &word, const string &target) {
    int diff = 0;

    for (int i = 0; word[i] != '\0'; ++i) {
        if (word[i] != target[i]) diff++;
    }

    if (diff == 1) return true;
    else return false;
}

bool isTargetAvailable(const string &target, const vector<string> &words) {
    for (int i = 0; i < words.size(); ++i) {
        if (target == words[i]) return true;
    }
    return false;
}

int bfs(const string &begin, const string &target, const vector<string> &words) {
    while (!q.empty()) {
        int prevSize = q.size();

        for (int i = 0; i < prevSize; ++i) {
            string current = q.front();
            q.pop();

            // 현재 단어가 타겟 단어와 같은 지 확인
            if (current == target) return cnt;

            // words 벡터 순회
            for (int j = 0; j < words.size(); ++j) {
                string tmp = words[j];
                // 변환 가능한 단어일 때
                if (isConvertible(current, tmp) && !isVisited[j]) {
                    isVisited[j] = true;
                    q.push(tmp);
                }
            }
        }

        cnt++;
    }

    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    // 제일 먼저 타겟 단어가 리스트 내부에 있는지 확인
    if (!isTargetAvailable(target, words)) return 0;

    q.push(begin);
    answer = bfs(begin, target, words);

    return answer;
}

int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};

    solution(begin, target, words);
}