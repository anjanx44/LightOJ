/*
USER:
TASK:
ALGO:
*/
/*
#pragma warning (disable: 4786)
#pragma comment (linker, "/STACK:0x800000")
*/
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }

#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const int MAX = 1001;

int G[MAX][MAX], deg[MAX];
int dp[MAX][2];

int solve(int u, int p, int t) {
	if(dp[u][t] != -1) return dp[u][t];
	int &ret = dp[u][t]; ret = t;
	int v, i;
	for(i = 0; i < deg[u]; i++) {
		v = G[u][i];
		if(v == p) continue;
		if(t) ret += solve(v, u, 0);
		else ret += max(solve(v, u, 1), solve(v, u, 0));
	}
	return ret;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, cs, n, e, i, u, v, ans;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &e);
		CLR(deg); SET(dp);
		for(i = 0; i < e; i++) {
			scanf("%d %d", &u, &v);
			G[u][deg[u]++] = v;
			G[v][deg[v]++] = u;
		}
		for(ans = 0, i = 1; i <= n; i++) {
			if(dp[i][0]==-1 || dp[i][1]==-1) {
				ans += max(solve(i, 0, 0), solve(i, 0, 1));
			}
		}
		printf("Case %d: %d\n", cs, ans);
	}
	return 0;
}

