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

/*
 * This class implements big Integers.
 * It currently can handle only unsigned integers.
 * The current range is 0 - 10^9000.
 * 
 * It stores the number as an integer array with base 10^9.
 */
class BigInt {
	string get_reverse_string_value(ll n) {
		if(n==0) return "0";

		string ret = "";
		while(n) { ret += '0' + (n%10); n /= 10;}
		return ret;
	}

	public:
		/* base to use to store as integer array. */
		static const ll mod = 1e9;

		/* integer array used to store the number. */
		ll num[1000];

		/* stores the next position in the array to be filled. */
		int pos;

		/* flag to check if the number is zero. */
		bool is_zero;


		/*
		 * Default constructor.
		 * Default value: 0.
		 */ 
		BigInt() { num[0] = 0; pos = 1; is_zero = true; }


		/* Constructor to construct a BigInt from a long long int. */
		BigInt(ll n) {
			if(n==0) { num[0] = 0; pos = 1; is_zero = true; return; }
			while(n) { num[pos] = n%mod; n /= mod; pos++; }
		}


		void set_next_index(ll val) {
			if(is_zero) { num[0] = val; pos = 1; is_zero = false; return; }
			num[pos] = val; pos++;
		}


		/* This method multiplies the current BigInt with an int. */
		BigInt multiply(int n) {
			BigInt ret = BigInt(0);
			if(n==0) return ret;

			ll carry = 0;
			rep(i,0,pos-1) {
				carry += num[i]*n; ret.set_next_index(carry%mod); carry /= mod;
			}

			while(carry) { ret.set_next_index(carry%mod); carry /= mod; }

			return ret;
		}


		string get_num_as_string() {
			string numString = "";
			rep(i,0,pos-1) numString += get_reverse_string_value(num[i]);
			reverse(all(numString));
			return numString;
		}


		void print() {
			cout<<get_num_as_string()<<endl;
		}
};

ll ans[10005];

ll get_sum_of_digits(BigInt num) {
	string numString = num.get_num_as_string();
	ll ret = 0;
	rep(i,0,sz(numString))
		ret += numString[i] - '0';

	return ret;
}


void preprocess() {
	BigInt num = BigInt(1);
	rep(i,0,10001) {
		ans[i] = get_sum_of_digits(num);
		num = num.multiply(2);
	}
}


void init() {
}

void solve(int test_case) {
	init();

	int n;
	cin>>n;
	cout<<ans[n]<<endl;

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
