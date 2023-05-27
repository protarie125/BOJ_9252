#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string a, b;
	cin >> a >> b;

	const auto& l1 = a.length();
	const auto& l2 = b.length();

	auto dp = vvi(l2 + 1, vi(l1 + 1, 0));
	for (auto i = 1; i <= l2; ++i) {
		const auto& nc = b[i - 1];
		for (auto j = 1; j <= l1; ++j) {
			if (nc == a[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				const auto& u = dp[i - 1][j];
				const auto& l = dp[i][j - 1];
				dp[i][j] = max(u, l);
			}
		}
	}

	std::cout << dp[l2][l1] << '\n';

	if (0 == dp[l2][l1]) {
		return 0;
	}

	auto oss = ostringstream{};
	auto x = l1;
	auto y = l2;
	while (0 < x && 0 < y) {
		if (0 == dp[y][x]) {
			break;
		}

		if (dp[y][x] == dp[y - 1][x]) {
			--y;
			continue;
		}

		if (dp[y][x] == dp[y][x - 1]) {
			--x;
			continue;
		}

		oss << a[x - 1];
		--x;
		--y;
	}

	auto ansstr = static_cast<string>(oss.str());
	std::reverse(ansstr.begin(), ansstr.end());
	std::cout << ansstr;

	return 0;
}