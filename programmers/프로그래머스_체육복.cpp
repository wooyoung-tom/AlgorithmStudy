//
// Created by djdj7 on 2020-03-15.
//

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n, 0);

    for(int i : reserve) students[i-1]++;
    for(int i : lost) students[i-1]--;

    for(int i = 0 ; i < n ; i++) {
        if(i == 0) {
            if(students[i] == -1) {
                if(students[i + 1] == 1) {
                    students[i] = 0;
                    students[i + 1] = 0;
                }
            }
        } else if(i == n-1) {
            if(students[i] == -1) {
                if(students[i - 1] == 1) {
                    students[i] = 0;
                    students[i - 1] = 0;
                }
            }
        } else {
            if(students[i] == -1) {
                if(students[i + 1] == 1) {
                    students[i] = 0;
                    students[i + 1] = 0;
                } else if (students[i - 1] == 1) {
                    students[i] = 0;
                    students[i - 1] = 0;
                }
            }
        }
    }

    for(int i = 0 ; i < n ; i++) {
        if(students[i] >= 0) answer++;
    }

    return answer;
}