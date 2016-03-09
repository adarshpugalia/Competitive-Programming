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
#define EPS 0.0000000000001
#define mod(a) ((a)%MOD)

#define bcnt __builtin_popcount 

ll ciel(double a) { ll ret = a; if(a-ret>EPS) ret++; return ret; }
bool double_compare(double a, double b) { return (a+EPS>b && a-EPS<b); }
 
using namespace std;

class Line {
	public:
		/* This represents the line in the form ax + by + c = 0. */
		double a, b, c;

		Line(double a_, double b_, double c_) { a = a_, b = b_, c = c_; };
		Line(Point i, Point j) { a = j.y - i.y; b = -(j.x - i.x); c = i.y*(-b) - i.x*a; }

		/* This method returns the value of a point on the line. */
		double get_value(Point i) { return a*i.x + b*i.y + c; }

		/* This method returns the shortest distance of the line from a point. */
		double get_distance(Point i) { return fabs(get_value(i))/pow(a*a + b*b, 0.5); }
};

int main() {
	return 0;
}