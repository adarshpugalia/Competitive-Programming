/*
 * Author: Adarsh Pugalia
 * Problem Link: http://codeforces.com/contest/148/problem/D
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

double dp[2][1005][1005];


void preprocess() {
}


void init() {
	rep(i,0,1000) {
		rep(j,0,1000)
			dp[0][i][j] = dp[1][i][j] = -1;
	}
}


double compute(int w, int b, int chance) {
	// if no mouse left return 0;
	if(w<=0)
		return 0;

	// if princess
	if(chance==0) {
		if(dp[0][w][b]!=-1)
			return dp[0][w][b];

		double ret = 0;
		// she draws a white mouse.
		ret += 1.0*w/(w+b);

		// she draws a black mouse.
		if(b>0)
			ret += 1.0*b*compute(w, b-1, 1)/(w+b);

		dp[0][w][b] = ret;
		return ret;
	}

	if(dp[1][w][b]!=-1)
		return dp[1][w][b];

	double ret = 0;
	// dragon draws a black mouse.
	if(b>0) {
		double temp = 1.0*b/(b+w);

		// if a white mouse jumps.
		double temp2 = 1.0*w*compute(w-1, b-1, 0)/(b-1+w);

		// if a black mouse jumps
		if(b-1>0) {
			temp2 += 1.0*(b-1)*compute(w, b-2, 0)/(b-1+w);
		}

		ret = temp*temp2;
	}

	dp[1][w][b] = ret;
	return ret;
}


void solve(int test_case) {
	init();

	int w, b;
	cin>>w>>b;

	double ans = compute(w, b, 0);
	printf("%0.10lf\n", ans);
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
