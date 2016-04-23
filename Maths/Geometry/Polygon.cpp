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
#define EPS 0.0001
#define GCD_EPS 0.0001
#define PI 3.14159265358979323846
#define mod(a) ((a)%MOD)

#define bcnt __builtin_popcount 

ll ciel(double a) { ll ret = a; if(a-ret>EPS) ret++; return ret; }
ll gcd(ll a, ll b) { if(a<b)return gcd(b, a); if(a%b==0)return b; return gcd(b, a%b); }
ll pow(ll n, ll p) {if(p==0)return 1; if(n<=1)return n;ll res = 1;while(p){if(p&1) res = mod(res*n);n = mod(n*n);p /= 2;} return res;}

double fgcd(double a, double b) { if(fabs(a)<fabs(b)) return fgcd(b, a); if(fabs(b)<GCD_EPS) return a; return fgcd(b, fmod(a,b)); }

bool db_db_cmp(double a, double b) { return (a+EPS>b && a-EPS<b); }
bool db_ll_cmp(double a, ll b) { bool ret = (a+EPS>b && a-EPS<b); if(ret) return ret; b++; return (a+EPS>b && a-EPS<b); }

using namespace std;

class Point {
	public:
		double x, y, z;

		Point(double a = 0, double b = 0, double c = 0) { x = a, y = b, z = c; }
		double get_distance(Point pt) { return pow((x-pt.x)*(x-pt.x) + (y-pt.y)*(y-pt.y) + (z-pt.z)*(z-pt.z), 0.5); }
		ll get_squared_distance(Point pt) { return (x-pt.x)*(x-pt.x) + (y-pt.y)*(y-pt.y) + (z-pt.z)*(z-pt.z); }

		/* 
		 * This method computes the turn for three points in order.
		 * returns +ve for anticlockwise order, 0 if the points are collinear, -ve for clockwise.
		 *
		 * NOTE: This is also twice the signed area of the traingle formed by the three points.
		 */
		double calculate_turn(Point i, Point j) { return (i.x-x)*(j.y-y) - (i.y-y)*(j.x-x); }

		/*
		 * This method returns the angle between three points.
		 * The current point is the centre, and the other two points its arms.
		 * 
		 * @return double: angle in radians.
		 */
		double get_angle(Point i, Point j) { 
			double b = get_distance(i), c = get_distance(j), a = i.get_distance(j); 
			return acos((b*b + c*c - a*a)/(2*b*c));
		}

		/*
		 * This method rotates a point around the current point by the given angle.
		 *
		 * NOTE: 1. Angle should be in radians.
		 		 2. Rotation is counter-clockwise..
		 */
		Point rotate(Point i, double angle) {
			Point ret;
			double s = sin(angle), c = cos(angle);
			
			i.x -= x, i.y -= y;
			ret.x = i.x*c - i.y*s; ret.y = i.x*s + i.y*c; ret.x += x, ret.y += y;
			return ret;
		}

		/* This method return the dot product between two points taken as vector from the origin. */
		double dot(Point i) { return x*i.x + y*i.y + z*i.z; }

		/* operator overloading. */
		bool operator==(const Point& i) { return db_db_cmp(x, i.x) && db_db_cmp(y, i.y) && db_db_cmp(z, i.z); }
		Point operator -(const Point &i) { Point ret(x, y, z); ret.x -= i.x, ret.y -= i.y, ret.z -= i.z; return ret; }

		/* input and output functions. */
		friend ostream &operator<<(ostream &output, const Point &pt) { output<<pt.x<<" "<<pt.y; return output; }
		friend istream &operator>>(istream &input, Point &pt) { input>>pt.x>>pt.y; return input; }
		void input() { cin>>x>>y>>z; }
		void output() { plf(x); ps; plf(y); ps; plf(z); pe; }
};


/*
 * This class represents an object polygon.
 *
 * @data vector<Point> pts: this stores the points of the polygon in order.
 */
class Polygon {
	public:
		vector<Point> pts;

		void clear() { pts.clear(); }
		void add(Point p) { pts.pb(p); }

		/* This method checks if the polygon is a rectangle. */
		bool is_rectangle() { 
			if(pts.size()!=4) return false;
			for(int i=0; i<4; i++) { if(!db_ll_cmp((pts[(i+1)%4]-pts[i]).dot(pts[(i+2)%4]-pts[(i+1)%4]), 0)) return false; }
			return true;
		}

		/* This method checks if the polygon is a square. */
		bool is_square() {
			if(!is_rectangle()) return false;
			double dis = pts[1].get_distance(pts[0]);
			for(int i=0; i<4; i++) if(!db_db_cmp(dis, pts[(i+1)%4].get_distance(pts[i]))) return false;
			return true;
		}
};

int main() {
	return 0;
}