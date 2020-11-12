//
// Created by 최우영 on 2020/11/12.
//

#include <iostream>
#include <string>
#include <algorithm>
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

bool compare(const string &first, const string &second) {
    int firstGenrePlay = albumMap[first].totalPlay;
    int secondGenrePlay = albumMap[second].totalPlay;

    if (firstGenrePlay < secondGenrePlay) return false;
    else return true;
}

bool playCompare(const pair<int, int> &first, const pair<int, int> &second) {
    int firstSongNum = first.first;
    int secondSongNum = second.first;
    int firstSongPlay = first.second;
    int secondSongPlay = second.second;

    // 1. 장르 내에서 많이 재생된 곡 순으로 정렬
    if (firstSongPlay > secondSongPlay) return true;
    else if (firstSongPlay < secondSongPlay) return false;
        // 2. 장르 내에 재생된 수가 같을 때
    else {
        // 2-1. 고유번호가 작은 수 부터
        if (firstSongNum > secondSongNum) return false;
        else return true;
    }
}

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
        albumMap[currentGenre].songInfoVector.emplace_back(i, currentPlay);
    }

    // 정렬 기준을 명확하게 하여야 한다.
    // 정렬 수행해서 재생 수 순으로 두어야 한다.
    // 현재 존재하는 장르 담아놓은 vector 를 기준으로 수행한다.

    // 현재 장르 플레이 수 내림차순으로 정렬한다.
    sort(genreContainer.begin(), genreContainer.end(), compare);

    // 장르 내림차순으로 정렬한 벡터를 순회한다.
    for (int i = 0; i < genreContainer.size(); ++i) {
        string currentGenre = genreContainer[i];
        genreInfo currentInfo = albumMap[currentGenre];
        vector<pair<int, int>> currentVector = currentInfo.songInfoVector;
        sort(currentVector.begin(), currentVector.end(), playCompare);

        if (currentVector.size() < 2) answer.push_back(currentVector[0].first);
        else {
            answer.push_back(currentVector[0].first);
            answer.push_back(currentVector[1].first);
        }
    }

    return answer;
}