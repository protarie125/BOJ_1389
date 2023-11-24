#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

constexpr auto Inf = numeric_limits<int>::max() / 2 - 1;

int N, M;
vvi adj;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> N >> M;

	adj = vvi(N, vi(N, Inf));
	while (0 < (M--)) {
		int u, v;
		cin >> u >> v;

		--u;
		--v;

		adj[u][v] = 1;
		adj[v][u] = 1;
	}

	for (auto k = 0; k < N; ++k) {
		for (auto i = 0; i < N; ++i) {
			for (auto j = 0; j < N; ++j) {
				if (i == j) {
					continue;
				}

				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	auto sums = vi(N, 0);
	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < N; ++j) {
			if (i == j) {
				continue;
			}

			sums[i] += adj[i][j];
		}
	}

	auto ans = 0;
	for (auto i = 0; i < N; ++i) {
		if (sums[i] < sums[ans]) {
			ans = i;
		}
	}

	cout << ans + 1;

	return 0;
}