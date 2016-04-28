/*
 * Author: 		Adarsh Pugalia
 * Problem: 	Find the number of parallelograms formed from n points such that no three are collinear.
 * Complexity: 	O(n^2log^2(n^2)) time.
 * Link: 		http://codeforces.com/contest/660/problem/D
 *
 * Idea:		Maintain a map for each slope, whose key is a map with (dist, number of pairs with that slope and distance.)
 *				So, number of parallelograms for each (slope,dis) is nC2.
 *				Take care of vertical and horizontal.
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
#define EPS 0.00000001
#define GCD_EPS 0.0001
#define PI 3.14159265358979323846
#define mod(a) ((a)%MOD)

#define bcnt __builtin_popcount 

ll ciel(double a) { ll ret = a; if(a-ret>EPS) ret++; return ret; }
int gcd(int a, int b) { if(a<b)return gcd(b, a); if(a%b==0)return b; return gcd(b, a%b); }
ll pow(ll n, ll p) {if(p==0)return 1; if(n<=1)return n;ll res = 1;while(p){if(p&1) res = mod(res*n);n = mod(n*n);p /= 2;} return res;}

double fgcd(double a, double b) { if(fabs(a)<fabs(b)) return fgcd(b, a); if(fabs(b)<GCD_EPS) return a; return fgcd(b, fmod(a,b)); }

bool db_db_cmp(double a, double b) { return (a+EPS>b && a-EPS<b); }
 
using namespace std;

void preprocess() {
}

void init() {
}

map<pii, map<ll, int> > m;
map<ll, int> mh;
map<ll,int> mv;
pii pts[max_size];

void solve(int test_case) {
	init();

	int n;
	sd(n);

	rep(i,1,n) {
		sd(pts[i].f); sd(pts[i].s);
	}

	rep(i,1,n) {
		rep(j,i+1,n) {
			int x = pts[j].f - pts[i].f;
			int y = pts[j].s - pts[i].s;

			ll dis = ((ll)(pts[j].f-pts[i].f))*(pts[j].f-pts[i].f) + ((ll)(pts[j].s-pts[i].s))*(pts[j].s-pts[i].s);

			if(y<0) {
				x = -x;
				y = -y;
			}

			if(y==0) {
				auto it = mh.find(dis);
				if(it!=mh.end())
					it->s++;
				else {
					mh[dis] = 1;
				}
			}
			else if(x==0) {
				auto it = mv.find(dis);
				if(it!=mv.end())
					it->s++;
				else {
					mv[dis] = 1;
				}
			}
			else {
				ll g = gcd(abs(x), y);
				x /= g;
				y /= g;

				auto it = m.find(mp(x, y));
				if(it!=m.end()) {
					auto it2 = it->s.find(dis);
					if(it2!=it->s.end()) {
						it2->s++;
					}
					else {
						it->s.insert(mp(dis, 1));
					}
				}
				else {
					map<ll, int> temp;
					temp.insert(mp(dis, 1));
					m.insert(mp(mp(x, y), temp));
				}
			}	
		}
	}

	int ans = 0;
	iter(it, m) {
		iter(it2, it->s) {
			ans += (it2->s)*(it2->s-1)/2;
		}
	}

	iter(it,mh) {
		ans += it->s*(it->s-1)/2;
	}

	iter(it, mv) {
		ans += it->s*(it->s-1)/2;
	}

	ans /= 2;
	pd(ans);
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
