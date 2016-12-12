/*
 * Jarvis: AC, it is, Mr. Stark!
 * Thank you, Jarvis!
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
#define EPS 0.000000001
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

int scan_d(){ int ip=getchar_unlocked(), ret=0, flag = 1; for(; ip<'0' || ip>'9'; ip=getchar_unlocked())if(ip=='-'){flag=-1; ip=getchar_unlocked(); break;}for(; ip>='0' && ip<='9'; ip=getchar_unlocked())ret=ret*10+ip-'0'; return flag*ret;}
ll scan_ll(){int ip=getchar_unlocked(), flag = 1; ll ret = 0; for(; ip<'0'||ip>'9'; ip=getchar_unlocked())if(ip=='-'){flag=-1; ip=getchar_unlocked(); break;}for(; ip>='0' && ip<='9'; ip=getchar_unlocked())ret = ret*10+ip-'0'; return flag*ret;}
void print_d(int n){if(n<0){n=-n; putchar_unlocked('-');}int i=10; char output_buffer[10]; do{output_buffer[--i]=(n%10)+'0'; n/=10;}while(n); do{putchar_unlocked(output_buffer[i]);}while(++i<10);}
void print_ll(ll n){if(n<0){n=-n; putchar_unlocked('-');}int i=21; char output_buffer[21]; do{output_buffer[--i]=(n%10)+'0'; n/=10;}while(n); do{putchar_unlocked(output_buffer[i]);}while(++i<21);}

 
using namespace std;

ll MAXIM = 1e12;
vl powers;
 
void preprocess() {
	rep(i,2,40) {
		for(int j=2; ; j++) {
			ll temp = 1;
			ll p = 1;
			while(p<=i) {
				temp *= j;
				if(temp>MAXIM)
					break;

				p++;
			}

			if(p<=i)
				break;

			powers.pb(temp);
		}
	}

	sort(all(powers));
}

int find_index(ll n) {
	int start = 0, end = powers.size()-1;
	while(start<end) {
		if(end-start<=1) {
			if(powers[end] <= n)
				return end;

			if(powers[start] <= n)
				return start;

			return -1;
		}

		int mid = (start+end)/2;

		if(powers[mid]<=n)
			start = mid;
		else
			end = mid-1;
 	}
}
 
 
void init() {
}
 
void solve(int test_case) {
	init();
 
	ll n;
	n = scan_ll();
 
	if(n==1) {
		cout<<"INFINITY\n";
		return;
	}
 
	if(n==2) {
		cout<<"1\n";
		return;
	}
 
	ll ans = n - (n/2);
	ans += find_index(n) - find_index(n/2);
 
	print_ll(ans); pe;
}
 
int main() {
	preprocess();
	int t = 1;
	sd(t);
 
	rep(i,1,t) {
		solve(i);
	}
	return 0;
} 
