/*
 * Author: Adarsh Pugalia
 * Problem Link: http://codeforces.com/contest/459/problem/E
 */ 
#include <bits/stdc++.h>

/* Data types and structures. */
#define ll long long int
#define llu long long int unsigned
#define vi vector <int>
#define vl vector <ll> 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector <pii >
#define vpll vector <pll >
 
/* Data structure helpers. */ 
#define f first
#define s second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define sz(n) (int)n.size()-1
#define all(n) n.begin(), n.end()
#define has(it,s) if(it!=s.end())
 
/* Input output defines. */
#define sd(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)
#define slf(n) scanf("%lf", &n) 
#define pd(n) printf("%d", n);
#define pl(n) printf("%lld", n);
#define plf(n) printf("%0.9lf", n);
#define ps printf(" ")
#define pe printf("\n")

/* loops */
#define rep(i,j,k) for(int i=j; i<=k; i++)
#define repd(i,j,k) for(int i=j; i>=k; i--)
#define iter(it, s) for(auto it=s.begin(); it!=s.end(); it++)

/* constraints. */ 
#define max_size 100005
#define max_sieve_size 1000005
#define max_matrix_size 100
#define max_log 17
#define INF 1000000000000000000
#define MOD 1000000007
#define EPS 0.0000000001
#define GCD_EPS 0.0001
#define PI 3.14159265358979323846
#define mod(a) ((a)%MOD)
#define bcnt __builtin_popcount 

using namespace std;

vector<pair<int, pii > > edges;
int dp[300005];
vector<pii > v;


void preprocess() {
}


void init() {
}


void solve(int test_case) {
	init();

	int n, m;
	cin>>n>>m;

	rep(i,1,m) {
		int a, b, c;
		sd(a); sd(b); sd(c);
		edges.pb(mp(c, mp(a, b)));
	}

	sort(all(edges));

	int ans = 0, i;
	int cur = 0;
	while(cur<edges.size()) {
		v.clear();
		for(i=cur; i<edges.size() && edges[cur].f==edges[i].f; i++) {
			v.pb(mp(edges[i].s.s, dp[edges[i].s.f]+1));
		}

		cur = i;

		rep(i,0,sz(v)) {
			dp[v[i].f] = max(dp[v[i].f], v[i].s);
			ans = max(ans, v[i].s);
		}
	}

	cout<<ans<<endl;
}

int main() {
	preprocess();
	int t = 1;
	//sd(t);
 
	rep(i,1,t) {
		solve(i);
	}
	return 0;
}
