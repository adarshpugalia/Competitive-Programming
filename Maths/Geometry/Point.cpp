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

class Point {
	public:
		double x, y, z;

		Point(double a = 0, double b = 0, double c = 0) { x = a, y = b, z = c; }
		double get_distance(Point pt) { return pow((x-pt.x)*(x-pt.x) + (y-pt.y)*(y-pt.y) + (z-pt.z)*(z-pt.z), 0.5); }

		/* operator overloading. */
		bool operator==(const Point& i) { return double_compare(x, i.x) && double_compare(y, i.y) && double_compare(z, i.z); }

		/* input and output functions. */
		friend ostream &operator<<(ostream &output, const Point &pt) { output<<pt.x<<" "<<pt.y; return output; }
		friend istream &operator>>(istream &input, Point &pt) { input>>pt.x>>pt.y; return input; }
		void input() { cin>>x>>y>>z; }
		void output() { plf(x); ps; plf(y); ps; plf(z); pe; }
};

int main() {
	return 0;
}