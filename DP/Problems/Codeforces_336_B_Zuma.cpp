/*
 * Author: Adarsh Pugalia
 * Problem link: http://codeforces.com/contest/607/problem/B
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

int num[505];
int ans[505][505];

void preprocess() {
}


int compute_dp(int start, int end) {
	if(end<start)
		return 100000;

	if(start==end)
		return 1;

	if(end-start==1) {
		if(num[start]==num[end])
			return 1;
		return 2;
	}

	if(ans[start][end])
		return ans[start][end];

	int ret = 1 + compute_dp(start+1, end);
	if(num[start+1]==num[start])
		ret = min(ret, 1 + compute_dp(start+2, end));

	rep(i,start+2,end-1) {
		if(num[start]==num[i])
			ret = min(ret, compute_dp(start+1, i-1) + compute_dp(i+1, end));
	}

	if(num[end]==num[start])
		ret = min(ret, compute_dp(start+1, end-1));

	ans[start][end] = ret;
	return ret;
}

void init() {
}


void solve(int test_case) {
	init();

	int n;
	sd(n);

	rep(i,1,n)
		cin>>num[i];


	cout<<compute_dp(1, n)<<endl;
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
