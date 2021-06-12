//
// Created by 최우영 on 2021/05/05.
//

#include <iostream>
#include <deque>

using namespace std;

int N;
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        string command;
        cin >> command;

        if (command == "push_front") {
            int X;
            cin >> X;
            dq.push_front(X);
        } else if (command == "push_back") {
            int X;
            cin >> X;
            dq.push_back(X);
        } else if (command == "pop_front") {
            if (dq.empty()) cout << -1 << "\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        } else if (command == "pop_back") {
            if (dq.empty()) cout << -1 << "\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        } else if (command == "size") {
            cout << dq.size() << "\n";
        } else if (command == "empty") {
            if (dq.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if (command == "front") {
            if (dq.empty()) cout << -1 << "\n";
            else cout << dq.front() << "\n";
        } else if (command == "back") {
            if (dq.empty()) cout << -1 << "\n";
            else cout << dq.back() << "\n";
        }
    }
}