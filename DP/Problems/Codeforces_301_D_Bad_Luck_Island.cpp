/*
 * Author: Adarsh Pugalia
 * Problem link: http://codeforces.com/contest/540/problem/D
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

double dp[3][105][105][105];
int vis[105][105][105];

void preprocess() {
}


void init() {
}

void solve(int r, int s, int p) {
	if(vis[r][s][p])
		return;

	vis[r][s][p] = 1;

	// if only r left
	if(s==0 && p==0) {
		dp[0][r][s][p] = 1;
		dp[1][r][s][p] = 0;
		dp[2][r][s][p] = 0;
	}

	// if only s are left
	if(r==0 && p==0) {
		dp[0][r][s][p] = 0;
		dp[1][r][s][p] = 1;
		dp[2][r][s][p] = 0;
	}

	// if only p are left
	if(r==0 && s==0) {
		dp[0][r][s][p] = 0;
		dp[1][r][s][p] = 0;
		dp[2][r][s][p] = 1;
	}

	int total = r+s+p;

	// if r and s met.
	if(r>0 && s>0) {
		double pro = (1.0*r*s)/(r*s + r*p + s*p);
		solve(r, s-1, p);

		if(r>0) {
			dp[0][r][s][p] += pro*dp[0][r][s-1][p];
		}

		if(s>1) {
			dp[1][r][s][p] += pro*dp[1][r][s-1][p];
		}

		if(p>0) {
			dp[2][r][s][p] += pro*dp[2][r][s-1][p];
		}
	}


	// if r and p met.
	if(r>0 && p>0) {
		double pro = (1.0*r*p)/(r*s + r*p + s*p);
		solve(r-1, s, p);

		if(r>1) {
			dp[0][r][s][p] += pro*dp[0][r-1][s][p];
		}

		if(s>0) {
			dp[1][r][s][p] += pro*dp[1][r-1][s][p];
		}

		if(p>0) {
			dp[2][r][s][p] += pro*dp[2][r-1][s][p];
		}
	}

	// if s and p met.
	if(s>0 && p>0) {
		double pro = (1.0*p*s)/(r*s + r*p + s*p);
		solve(r, s, p-1);

		if(r>0) {
			dp[0][r][s][p] += pro*dp[0][r][s][p-1];
		}

		if(s>0) {
			dp[1][r][s][p] += pro*dp[1][r][s][p-1];
		}

		if(p>1) {
			dp[2][r][s][p] += pro*dp[2][r][s][p-1];
		}
	}
}


void solve(int test_case) {
	init();

	int r, s, p;
	cin>>r>>s>>p;

	solve(r, s, p);

	printf("%0.10lf %0.10lf %0.10lf\n", dp[0][r][s][p], dp[1][r][s][p], dp[2][r][s][p]);
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
