//
// Created by djdj7 on 2020-05-04.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> container;
    int answer = 0;

    for (int i = 0; i < moves.size(); i++) {
        int num_row = board.size();
        int col = moves[i]-1;
        for (int row = 0; row < num_row; row++) {
            if(board[row][col] != 0) {
                if(!container.empty()) {
                    if(container[container.size()-1] == board[row][col]) {
                        container.pop_back();
                        answer += 2;
                    } else {
                        container.push_back(board[row][col]);
                    }
                } else {
                    container.push_back(board[row][col]);
                }
                board[row][col] = 0;
                break;
            } else {
                continue;
            }
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> board = {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 3},
            {0, 2, 5, 0, 1},
            {4, 2, 4, 4, 2},
            {3, 5, 1, 3, 1}};
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};

    solution(board, moves);
}