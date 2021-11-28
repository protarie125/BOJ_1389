#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<int, vector<int>> adjs{};

int dist(int N, int from, int to) {
    vector<bool> isVisited(N, false);
    queue<pair<int, int>> q{};
    q.push({ from, 0 });

    while (!q.empty()) {
        auto f = q.front();
        if (to == f.first)
            return f.second;

        q.pop();
        isVisited[f.first - 1] = true;

        for (const auto& v : adjs[f.first])
        {
            if (!isVisited[v - 1]) {
                q.push({ v, f.second + 1 });
            }
        }
    }

    return 987654321;
}

int solve(int N) {
    int result{ 0 };
    int minDist{ 987654321 };

    for (int i = 1; i <= N; ++i) {
        int sum{ 0 };
        for (int j = 1; j <= N; ++j)
        {
            if (j == i)
                continue;

            sum += dist(N, i, j);
        }

        if (sum < minDist) {
            minDist = sum;
            result = i;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        adjs[i] = vector<int>{};
    }

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;

        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }

    cout << solve(N);

    return 0;
}