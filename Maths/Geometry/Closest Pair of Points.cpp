/*
 * Author: 		Adarsh Pugalia
 * Algorithm: 	Closest pair of points from a set of n points.
 * Complexity: 	O(nlogn)
 *
 * This is a sweep line implementation.
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
#define EPS 0.00000000001
#define GCD_EPS 0.0001
#define PI 3.14159265358979323846
#define mod(a) ((a)%MOD)

#define bcnt __builtin_popcount 

ll ciel(double a) { ll ret = a; if(a-ret>EPS) ret++; return ret; }
ll gcd(ll a, ll b) { if(a<b)return gcd(b, a); if(a%b==0)return b; return gcd(b, a%b); }
ll pow(ll n, ll p) {if(p==0)return 1; if(n<=1)return n;ll res = 1;while(p){if(p&1) res = mod(res*n);n = mod(n*n);p /= 2;} return res;}

double fgcd(double a, double b) { if(fabs(a)<fabs(b)) return fgcd(b, a); if(fabs(b)<GCD_EPS) return a; return fgcd(b, fmod(a,b)); }

bool db_db_cmp(double a, double b) { return (a+EPS>b && a-EPS<b); }

using namespace std;

class Point {
	public:
		double x, y, z;

		Point(double a = 0, double b = 0, double c = 0) { x = a, y = b, z = c; }
		double get_distance(Point pt) { return pow((x-pt.x)*(x-pt.x) + (y-pt.y)*(y-pt.y) + (z-pt.z)*(z-pt.z), 0.5); }
		ll get_squared_distance(Point pt) { return (x-pt.x)*(x-pt.x) + (y-pt.y)*(y-pt.y) + (z-pt.z)*(z-pt.z); }

		
		/* 
		 * comparator method for the points. 
		 * Sorts points according to their angle with +x-axis.
		 * In case of tie, points closer to origin are sorted first.
		 */
		//@not_tested
		bool operator<(const Point &p) const { 
			if(db_db_cmp(x, p.x))
				return y<p.y;

			return x<p.x;
		}

		/* operator overloading. */
		bool operator==(const Point& i) { return db_db_cmp(x, i.x) && db_db_cmp(y, i.y) && db_db_cmp(z, i.z); }
		Point operator -(const Point &i) { Point ret(x, y, z); ret.x -= i.x, ret.y -= i.y, ret.z -= i.z; return ret; }

		/* input and output functions. */
		friend ostream &operator<<(ostream &output, const Point &pt) { output<<pt.x<<" "<<pt.y; return output; }
		friend istream &operator>>(istream &input, Point &pt) { input>>pt.x>>pt.y; return input; }
		void input() { cin>>x>>y>>z; }
		void output() { plf(x); ps; plf(y); ps; plf(z); pe; }
}origin;

/* 
 * This is a comparator that sorts the points on the basis of y-cordinate. 
 * The points are otherwise sorted by x-cordinate using the default comparator.
 */
class YComparator { public: bool operator()(const Point& i, const Point&j) { return i.y<j.y; } };


/*
 * This class implements the closest pair of points algorithm.
 * @data pts:              stores the points in the set. (sorted by x-cordinate)
 * @data current_box:      stores the points currently under consideration while sweeping the line.
 *                         sorted by y-cordinate.
 * @data closest_distance: closest distance encountered as of now.
 * @data closest_pair: 	   closest pair encountered as of now.
 *
 * NOTE: Initialize the constructor with the maximum possible square of distance.
 */
class ClosestPairOfPoints {
	public:
		set<Point> pts;
		set<Point, YComparator> current_box;
		ll closest_distance;
		pair<Point, Point> closest_pair;

		/* constructors. */
		ClosestPairOfPoints() {}
		ClosestPairOfPoints(ll inf) { closest_distance = inf; }

		/* This method inserts a point in the set. */
		void add_point(Point p) { pts.insert(p); }

		/* This method returns one of the closest pair of points. */
		pair<Point, Point> get_closest_pair() {
			auto it = pts.begin(), it2 = pts.begin(); current_box.insert(*it);
			for(it++; it!=pts.end(); it++) {
				/* removing the points not necessary. */
				while(it2!=it && (it->x-it2->x)*(it->x-it2->x)>closest_distance) { current_box.erase(*it2); it2++; }

				/* updating the closest distance with the current box. */
				Point temp = Point(it->x-pow(closest_distance, 0.5), it->y-pow(closest_distance, 0.5));
				for(auto it3 = current_box.lower_bound(temp); it3!=current_box.end() && (it->y-it3->y)*(it->y-it3->y)<=closest_distance; it3++) {
					if(Point(*it).get_squared_distance(Point(*it3))<closest_distance) {
						closest_distance = Point(*it).get_squared_distance(Point(*it3)); closest_pair = mp(*it, *it3);
					}
				}
				current_box.insert(*it);
			}
			return closest_pair;
		}
};

ClosestPairOfPoints cpp = ClosestPairOfPoints(2e18);
int main() {
	
	return 0;	
}