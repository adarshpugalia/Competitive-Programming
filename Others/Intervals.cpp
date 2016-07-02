/*
 * Author: Adarsh Pugalia
 * Problem Link: https://www.codechef.com/JULY16/problems/CHSGMNTS
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

using namespace std;

/*
 * This class implements operations on positive intervals.
 *
 * NOTE: The intervals should not overlap.
 */
template <class T>
class Intervals {
	public:
		set<pair<T,T> > intervals;	

		/*
		 * This method returns the interval to which a given element belongs.
		 * @param i: the element whose interval is to be fetched.
		 * return pair<T,T>: the interval to which the element belongs.
		 *
		 * NOTE: if the element does not belong to any interval, the method
		 * returns a pair of (-1, -1)
		 */
		pair<T,T> get_interval(T i) {
			auto it = intervals.lower_bound(mp(i,i));

			/* if the interval begins with the element. */
			if(it!=intervals.end() && it->f==i)
				return *it;

			/* if the first interval begins with an element greater than the element. */
			if(it==intervals.begin())
				mp(-1, -1);

			it--;

			/* if the interval contains the element. */
			if(it->f<=i && it->s>=i)
				return *it;

			return mp(-1, -1);
		}


		/*
		 * This method removes a point from the list of intervals.
		 *
		 * For example, if there is an interva (5,10), and remove_point(7) is called.
		 * the method would erase (5,10) and add (5,6) and (8,10).
		 */
		void remove_point(T i) {
			pair<T,T> interval = get_interval(i);

			/* if the interval does not contain the point, return. */
			if(interval.f==-1)
				return;

			/* case 1: the interval begins and ends at i. */
			if(interval.f==i && interval.s==i) {
				intervals.erase(interval);
				return;
			}

			/* case 2: the interval begins at i. */
			if(interval.f==i) {
				pair<T,T> temp = interval;
				temp.f++;

				intervals.erase(interval);
				intervals.insert(temp);
				return;
			}


			/* case 3: the interval ends at i. */
			if(interval.s==i) {
				pair<T,T> temp = interval;
				temp.s--;

				intervals.erase(interval);
				intervals.insert(temp);
				return;
			}


			/* case 4: i lies in between the interval. */
			intervals.insert(mp(interval.f, i-1));
			intervals.insert(mp(i+1, interval.s));
			intervals.erase(interval);
		}


		void add_interval(pair<T,T> i) { intervals.insert(i); }
		void remove_interval(pair<T,T> i) { intervals.erase(i); }
		void clear() { intervals.clear(); }
};

Intervals<int> intervals;



int main() {
	return 0;
}
