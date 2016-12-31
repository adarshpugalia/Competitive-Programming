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

ll ciel(double a) { ll ret = a; if(a-ret>EPS) ret++; return ret; }
ll gcd(ll a, ll b) { if(a<b)return gcd(b, a); if(a%b==0)return b; return gcd(b, a%b); }

/* This method does modular exponentiation in log(n). */
ll pow(ll n, ll p) {if(p==0)return 1; if(n<=1)return n;ll res = 1;while(p){if(p&1) res = mod(res*n);n = mod(n*n);p /= 2;} return res;}

double fgcd(double a, double b) { if(fabs(a)<fabs(b)) return fgcd(b, a); if(fabs(b)<GCD_EPS) return a; return fgcd(b, fmod(a,b)); }

/* This method compares whether two doubles are (almost) equal. */
bool db_db_cmp(double a, double b) { return (a+EPS>b && a-EPS<b); }

 
using namespace std;

class NumberTheory {
	static const int MAX_SIEVE_SIZE = 100005;
	static const int MAX_FACT_SIZE = 100005;

	int sieve[MAX_SIEVE_SIZE];
	vector <int> primes;

	void calc_sieve(int n) {
	    rep(i,0,n-1) sieve[i] = i;

	    rep(i,2,n-1) {
	        if(sieve[i]==i) {
	            primes.pb(i);
	            for(int j=i; j<n; j+=i) sieve[j] = min(sieve[j], i);
	        }
	    }
	}


	void generate_factorials(int n) {
		fact[0] = fact[1] = 1;
		rep(i,1,n-1)
			fact[i] = mod(fact[i-1]*i);
	}


	ll mod_pow(ll n, ll power, ll mod) {
		if(p==0) return 1; 
		if(n<=1)return n;

		ll res = 1;
		while(p){
			if(p&1) res = (res*n)%mod; 
			n = (n*n)%mod; 
			p /= 2;
		} 

		return res;
	}


	/* This method returns the modular inverse of a number (MOD must be prime). */
	ll get_inverse(ll n) {
		return pow(n, MOD-2);
	}


	/* This method return nCr modulo MOD. */
	void get_nCr(ll n, ll r) {
		ll ret = fact[n];
		ret = mod(ret*get_inverse(mod(fact[r]*fact[n-r])));
	}


	void init() {
		calc_sieve(MAX_SIEVE_SIZE);
		generate_factorials(MAX_FACT_SIZE);
	}


	ll phi (ll n) {
		ll result = n;
		for (ll i=2; i*i<=n; ++i) {
			if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; }
		}

		if (n > 1) result -= result / n;
		return result;
	}


	bool is_primitive_root(ll n, ll p) {
		int s = p-1;

		for(int i=0; i<primes.size() && primes[i]*primes[i]<=s; i++) {
			if(s%primes[i] == 0) {
				while(s%primes[i] == 0) s /= primes[i];
				
				if(mod_pow(n, (p-1)/primes[i], p) == 1)
					return false;
			}
		}

		if(s>1) {
			if(mod_pow(n, (p-1)/s, p) == 1)
				return false;
		}

		return true;
	}
}