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
#define plf(n) printf("%0.9lf\n", n);
#define ps printf(" ")
#define pe printf("\n")

/* loops */
#define rep(i,j,k) for(int i=j; i<=k; i++)
#define repd(i,j,k) for(int i=j; i>=k; i--)
#define iter(it, s) for(auto it=s.begin(), it!=s.end(); it++)

/* constraints. */ 
#define max_size 1000005
#define max_sieve_size 1000005
#define max_log 17
#define INF 1000000000000000000
#define MOD 1000000007
#define EPS 0.00000001
#define mod(a) ((a)%MOD)
 
using namespace std;

class Long {
	public:
		static const ll mod = 1e9 + 7;
		ll val;

		/* construtors. */
		Long() { val = 0; }
		Long(ll v) { val = v%mod; }

		Long pow(Long n, ll p) {
			if(n==0) return Long(0); if(n==1 || p==0) return Long(1);
			Long ret = 1; while(p) { if(p&1) { ret = ret*n; } n = n*n; p /= 2; }
			return ret;
		}

		/* operator overloading. */
		Long operator+(const Long& i) { return (val + i.val)%mod;}
		Long operator-(const Long& i) { return (val - i.val + mod)%mod;}
		Long operator*(const Long& i) { return (val*i.val)%mod; }
		Long operator/(const Long& i) { return (val*(pow(i,mod-2).val))%mod; }
		Long operator++() { return (val+1)%mod; }
		Long operator--() { return (val-1+mod)%mod; }

		bool operator<(const Long& i) { return val<i.val; }
		bool operator>(const Long& i) { return val>i.val; }
		bool operator==(const Long& i) { return val==i.val; }
		bool operator<=(const Long& i) { return val<=i.val; }
		bool operator>=(const Long& i) { return val>=i.val; }

		/* input and output functions. */
		friend ostream &operator<<(ostream &output, const Long &a) { output<<a.val; return output; }
		friend istream &operator>>(istream &input, Long &a) { input>>a.val; a.val %= a.mod; return input; }
};

int main() {
	return 0;
}