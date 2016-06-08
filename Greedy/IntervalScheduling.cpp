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

using namespace std;

/*
 * This class defines an interval.
 * @data start: start time of an interval.
 * @data end:	end time of an interval.
 *
 * NOTE: The intervals are sorted be their end times for 
 * 		 default interval scheduling.
 */
class Interval {
	public:
		ll start, end;

		Interval() { start = end = 0; }
		Interval(ll s, ll e) { start = s, end = e; }

		/* default comparator for intervals. */
		bool operator<(const Interval &i) const { 
			if(end==i.end)
				return start<i.start;
			return end<i.end;
		}
};


/*
 * This class implents the interval scheduling algorithms.
 * @data intervals: the set of intervals to be scheduled.
 * @method add_interval(start, end): to add an interval.
 * @method get_maximum_scheduling(): to get the maximum intervals scheduled.
 *
 * TODO: Currently it allows only one interval at a time to be scheduled.
 *		 Extend it to allow 'n' intervals to be scheduled at a time.
 */
class IntervalScheduling {
	public:
		set<Interval> intervals;


		/*
	     * This method adds an interval to the set.
	     * @data start: start time of interval.
	     * @data end  : end time of interval.
	     */
		void add_interval(ll start, ll end) { intervals.insert(Interval(start, end)); }


		/* This method returns the maximum intervals that can be scheduled. */
		int get_maximum_scheduling() {
			int ret = 0;

			/* NOTE: make sure this does not overlap with any interval. */
			Interval cur = Interval(-1e10, -1e10);
			
			iter(it, intervals) {
				if(it->start>=cur.end) { ret++; cur = *it;}
			}

			return ret;
		}
}is;

int main() {
	return 0;
}