/*
 * Author: 		Adarsh Pugalia
 * Algorithm: 	Convex hull trick.
 * 				Given a set of lines, find the minimum value at any given x.
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

ll ciel(double a) { ll ret = a; if(a-ret>EPS) ret++; return ret; }
ll gcd(ll a, ll b) { if(a<b)return gcd(b, a); if(a%b==0)return b; return gcd(b, a%b); }
ll pow(ll n, ll p) {if(p==0)return 1; if(n<=1)return n;ll res = 1;while(p){if(p&1) res = mod(res*n);n = mod(n*n);p /= 2;} return res;}

double fgcd(double a, double b) { if(fabs(a)<fabs(b)) return fgcd(b, a); if(fabs(b)<GCD_EPS) return a; return fgcd(b, fmod(a,b)); }

bool db_db_cmp(double a, double b) { return (a+EPS>b && a-EPS<b); }
 
using namespace std;

/*
 * This class implements a line of the form y = mx+c.
 *
 * NOTE: The members m and c are implemented as ll. Please change it to double
 *		 if required.
 */
class Line {
	public:
		ll m, c;

		/* The constructors for the class. */
		Line() { m = 0, c = 0; };
		Line(ll a_, ll b_) { m = a_; c = b_; }

		/* comparator method for the objects. */
		bool operator<(const Line &a) const { return m<a.m; }

		/* This method returns the value of y for a given x. */
		ll get_value(ll x) { return m*x + c; }

		/* This method checks if a given line is parallel to the current line.*/
		bool is_parallel(Line a) { return m==a.m; }

		/* 
		 * This method returns the x coordinate of intersection of a given line with the current line. 
		 * 
		 * NOTE: The method assumes that the lines are not parallel.
		 */
		double get_x_intersection(Line a) { return 1.0*(c-a.c)/(a.m-m); }

		friend ostream &operator<<(ostream &output, const Line &l) { output<<l.m<<":"<<l.c; return output; }
};

/*
 * This class implents the object for convex hull trick.
 * This is generally used in DP optimizations.
 *
 * @data lines: 			the set of lines currently in the hull.
 * @data x_cords:			the set of x_cordinates where minima changes from one line to another.
 * @data type:				the type of query: minimum query, or maximum query.
 * @data x_cord_line_map:	map that links x_cord to the corresponding line.
 * @data line_x_cord_map:	map that line to the corresponding x_cord.
 */
class ConvexHullTrick {
	public:
		set<Line> lines;
		set<double> x_cords;
		enum Type {MAX_QUERY, MIN_QUERY} type;
		map<double, Line> x_cord_line_map;
		map<Line, double> line_x_cord_map;
		double infinity;

		/* Constructors */
		ConvexHullTrick() {}
		ConvexHullTrick(Type t, double inf) { type = t; infinity = inf; }

		/* This method checks if the current element has a previous element in the set. */
		bool has_previous(set<Line>::iterator it) { return it!=lines.begin(); }

		/* This method checks if the current element has a next element in the set. */
		bool has_next(set<Line>::iterator it) { return (it!=lines.end() && next(it)!=lines.end()); }

		/* This method checks if the line b is irrelavant. */
		bool is_irrelavant(Line a, Line b, Line c) { return a.get_x_intersection(c) <= a.get_x_intersection(b); }

		/* This method checks if a line is irrelavant. */
		bool is_irrelavant(set<Line>::iterator it) { 
			if(has_previous(it) && has_next(it)) {
				if(type==MAX_QUERY) return is_irrelavant(*prev(it), *it, *next(it));
				return is_irrelavant(*next(it), *it, *prev(it));
			}
			return false;
		}

		/* This method updates the start point for a line (where it achieves minima or maxima). */
		void update_start_point(set<Line>::iterator it) {
			double x; Line l = *it;
			if(type==MAX_QUERY) { if(has_previous(it)) x = l.get_x_intersection(*prev(it)); else x = -infinity; }
			else { if(has_next(it)) x = l.get_x_intersection(*next(it)); else x = -infinity; }
			x_cords.insert(x); x_cord_line_map.insert(mp(x, *it)); line_x_cord_map.insert(mp(*it, x));
		}

		/* This method deletes the line from the set and the associated entries. */
		void erase_line(Line a) {
			x_cords.erase(line_x_cord_map.find(a)->s); x_cord_line_map.erase(x_cord_line_map.find(line_x_cord_map.find(a)->s));
			line_x_cord_map.erase(line_x_cord_map.find(a)); lines.erase(a);
		}

		void insert_line(Line a) {
			auto it = lines.lower_bound(a);
			
			/* checking if a parallel line is present. */
			if(it!=lines.end() && a.is_parallel(*it)) {
				if(type==MAX_QUERY && it->c<a.c) erase_line(*it); else if(type==MIN_QUERY && it->c>a.c) erase_line(*it);
				else return;
			}

			/* checking if the current inserted line is irrelavant. */
			lines.insert(a); it = lines.find(a);
			if(is_irrelavant(it)) { erase_line(a); return; };

			/* checking if the current line has made lines before it irrelavant. */
			while(has_previous(it) && is_irrelavant(prev(it))) { erase_line(*prev(it)); it = lines.find(a); }

			/* checking if the current line has made lines after it irrelavant. */
			while(has_next(it) && is_irrelavant(next(it))) { erase_line(*next(it)); it = lines.find(a); }

			it = lines.find(a);
			if(type==MAX_QUERY) { update_start_point(it); if(has_next(it)) update_start_point(next(it)); }
			else { update_start_point(it); if(has_previous(it)) update_start_point(prev(it)); }

		}

		/* The method returns the maximum/minimum value at a point. */
		double get_value(double x) {
			auto it = x_cords.lower_bound(x); it--; 
			Line line = x_cord_line_map.find(*it)->s; return line.get_value(x);
		}

		/* This method outputs the lines and map of the hull. */
		friend ostream &operator<<(ostream &output, const ConvexHullTrick &cvt) { 
			output<<"Line Set:\n"; iter(it, cvt.lines) output<<*it<<endl;
			output<<"X_Cord Set:\n"; iter(it, cvt.x_cords) output<<*it<<endl;
			output<<"Line Map:\n"; iter(it, cvt.line_x_cord_map) output<<it->f<<" "<<it->s<<endl;
			output<<"X_Cord Map:\n"; iter(it, cvt.x_cord_line_map) output<<it->f<<" "<<it->s<<endl;
			return output; 
		}
};

int main() {
	return 0;
}