//
// Created by 최우영 on 2020/11/01.
//

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct genreInfo {
    // 해당 장르 총 재생 수
    int totalPlay;
    // 고유 번호와 해당 곡 재생 수 담을 vector
    vector<pair<int, int>> songInfoVector;
};

// 장르 이름과 해당 장르 정보 매핑할 Map
unordered_map<string, genreInfo> albumMap;
// 현재 존재하는 장르 담아놓기 위한 vector
vector<string> genreContainer;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    // 장르 기준으로 순회한다. (어차피 plays 같음)
    for (int i = 0; i < genres.size(); ++i) {
        string currentGenre = genres[i];
        int currentPlay = plays[i];

        // 현재 장르의 총 재생 수가 0 이면 장르 vector 에 담는다.
        if (albumMap[currentGenre].totalPlay == 0) {
            genreContainer.push_back(currentGenre);
        }

        // 해당 장르 플레이 수 더한다.
        albumMap[currentGenre].totalPlay += currentPlay;
        // 고유 번호랑 플레이 수 벡터에 넣는다.
        albumMap[currentGenre].songInfoVector.push_back(make_pair(i, currentPlay));
    }

    return answer;
}

void input() {

}

int main() {
//    input();
}