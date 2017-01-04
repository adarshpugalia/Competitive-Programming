/*
 * Problem link: https://www.hackerrank.com/challenges/borrowing-money
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
#define pq priority_queue
 
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

/* General maths functions. */
ll ciel(double a) { ll ret = a; if(a-ret>EPS) ret++; return ret; }
ll gcd(ll a, ll b) { if(a<b)return gcd(b, a); if(a%b==0)return b; return gcd(b, a%b); }
double fgcd(double a, double b) { if(fabs(a)<fabs(b)) return fgcd(b, a); if(fabs(b)<GCD_EPS) return a; return fgcd(b, fmod(a,b)); }

/* This method compares whether two doubles are (almost) equal. */
bool db_db_cmp(double a, double b) { return (a+EPS>b && a-EPS<b); }

/* This method generates modular factorials. */
#define max_fact_size 100005
ll fact[max_fact_size];
void generate_factorials() { fact[0] = fact[1] = 1; rep(i,2,max_fact_size-1) fact[i] = mod(fact[i-1]*i); }

ll pow(ll n, ll p) { if(p==0) return 1; if(n<=1) return n; ll res = 1; while(p) { if(p&1) res = res*n; n = n*n; p /= 2; } return res; } 

/* This method does modular exponentiation in log(n). */
ll mod_pow(ll n, ll p) {if(p==0)return 1; if(n<=1)return n;ll res = 1;while(p){if(p&1) res = mod(res*n);n = mod(n*n);p /= 2;} return res;}

/* This method returns the modular inverse of a number (MOD must be prime). */
ll get_inverse(ll n) { return mod_pow(n, MOD-2);}

/* This method return nCr modulo MOD. */
ll get_nCr(ll n, ll r) { return mod(fact[n]*get_inverse(mod(fact[r]*fact[n-r]))); }

/* End of maths functions. */

using namespace std;


void preprocess() {
}


void init() {
}

void solve(int test_case) {
	init();

}

int nodes[50][50];
int cash[50];
int val[(1LL<<18) + 5];
int dp[(1LL << 18) + 5];
ll hm[(1LL << 18) + 5];

/*
 * This method computes the maximum cash and number of ways from any subset possible for a given mask.
 */
void recurse(int current, int N, int current_cost, ll current_mask, ll mask) {
	if(current == N) {
		//if(current_mask > 0) {
			if(dp[mask] < val[current_mask]) {
				dp[mask] = val[current_mask];
				hm[mask] = 1;
			} else if(dp[mask] == val[current_mask]) {
				hm[mask]++;
			}
		return;
	}

	recurse(current+1, N, current_cost, current_mask, mask);
	if(mask & (1LL << current)) {
		recurse(current+1, N, current_cost + cash[current+1], current_mask | (1LL << current), mask);
	}
}

pll ans;

/*
 * This method computes the best way and cash, combining the rest n/2 group with the 
 * previous one.
 */
void recurse2(int current, int N, int n, ll current_cost, ll current_mask) {
	if(current == n) {
		bool is_independent_set = true;
		rep(i,N,n-1) {
			rep(j,N,n-1) {
				if((current_mask & (1LL << i)) && (current_mask & (1LL << j)) && nodes[i+1][j+1]) {
					is_independent_set = false;
				}
			}
		}

		if(!is_independent_set)
			return;

		ll allowed_mask = 0;
		rep(i,0,N-1) {
			bool allowed = true;
			rep(j,N,n-1) {
				if((current_mask & (1LL << j)) && nodes[i+1][j+1]) {
					allowed = false;
				}
			}

			if(allowed)
				allowed_mask |= (1LL << i);
		}

		if(ans.f == current_cost + dp[allowed_mask]) {
			ans.s += hm[allowed_mask];
		} else if(ans.f < current_cost + dp[allowed_mask]) {
			ans = mp(current_cost + dp[allowed_mask], hm[allowed_mask]);
		}

		return;
	}

	recurse2(current+1, N, n, current_cost, current_mask);
	recurse2(current+1, N, n, current_cost + cash[current+1], current_mask | (1LL << current));
}


int main() {
	int n, m;
	cin>>n>>m;

	rep(i,1,n) {
		cin>>cash[i];
	}

	rep(i,1,m) {
		int a, b;
		cin>>a>>b;

		nodes[a][b] = 1;
		nodes[b][a] = 1;
	}

	int N = n/2;
	for(ll mask=1; mask < (1LL << N); mask++) {
		bool is_independent_set = true;

		rep(i,0,N-1) {
			rep(j,0,N-1) {
				if((mask & (1LL << i)) && (mask & (1LL << j)) && nodes[i+1][j+1]) {
					is_independent_set = false;
				}
			}
		}

		if(!is_independent_set) {
			/*
			 * This does not allow subsets that are not possible
			 * to end up being added.
			 */
			val[mask] = -1;
			continue;
		}

		rep(i,0,N-1) {
			if(mask & (1LL << i)) {
				val[mask] += cash[i+1];
			}
		}
	}

	for(ll mask = 1; mask < (1LL << N); mask++) {
		recurse(0, N, 0, 0, mask);
	}

	hm[0] = 1;

	ans = mp(0, 0);
	recurse2(N, N, n, 0, 0);
	cout<<ans.f<<" "<<ans.s<<endl;
}
