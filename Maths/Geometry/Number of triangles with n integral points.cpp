/*
 * Author: 		Adarsh Pugalia
 * Problem:		Number of triangles with n integral points.
 * Complexity:	O(n^2log(n))
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
#define max_size 2005
#define max_sieve_size 1000005
#define max_matrix_size 100
#define max_log 17
#define INF 1000000000000000000
#define MOD 1000000007
#define EPS 0.0000000000001
#define PI 3.14159265358979323846
#define mod(a) ((a)%MOD)

#define bcnt __builtin_popcount 

ll ciel(double a) { ll ret = a; if(a-ret>EPS) ret++; return ret; }
ll gcd(ll a, ll b) { if(a<b)return gcd(b, a); if(a%b==0)return b; return gcd(b, a%b); }
ll pow(ll n, ll p) {if(p==0)return 1; if(n<=1)return n;ll res = 1;while(p){if(p&1) res = mod(res*n);n = mod(n*n);p /= 2;} return res;}

bool double_compare(double a, double b) { return (a+EPS>b && a-EPS<b); }
 
using namespace std;

pll points[max_size];
map<pll, int> m;

void preprocess() {
}

void init() {
}

void solve(int test_case) {
	init();

	int n;
	sd(n);

	rep(i,1,n) {
		cin>>points[i].f>>points[i].s;
	}

	ll ans = 0;
	for(int i=1; i<n-1; i++) {
		m.clear();
		ll total = n-i;
		ll horizontal = 0, vertical = 0;

		for(int j=i+1; j<=n; j++) {
			ll x = points[j].f - points[i].f;
			ll y = points[j].s - points[i].s;

			if(x==0)
				vertical++;
			else if(y==0)
				horizontal++;
			else {
				if(y<0) {
					x = -x;
					y = -y;
				}

				ll g = gcd(abs(x), y);
				x /= g;
				y /= g;

				if(m.find(mp(x, y))==m.end())
					m[mp(x, y)] = 1;
				else
					m[mp(x, y)]++;
			}
		}

		ans += horizontal*(total - horizontal);
		ans += vertical*(total - vertical);

		for(auto it = m.begin(); it!=m.end(); it++) {
			ans += it->s*(total - it->s);
		}
	}

	cout<<ans/2<<endl;
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
