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
#define pq priority_queue
 
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

class Clique {
	public:
		/*
		 * This method returns the maximum number of edges possible for a graph with
		 * a given number of nodes, such that it does not have a clique of a given size.
		 * Turan's theorem gives this bound- https://en.wikipedia.org/wiki/Tur%C3%A1n%27s_theorem
		 *
		 * The exact formula that works is this:
		 * http://cs.stackexchange.com/questions/41057/minimum-size-of-largest-clique-in-graph
		 * 
		 * @param node_size: the number of nodes in the graph.
		 * @param clique_size: the size of the clique.
		 * @return ll: maximum number of edges such that the graph does not have a clique
		 *			   size clique size.
		 */
		ll get_max_edges_for_clique_free_graph(ll node_size, ll clique_size) {
			ll r = clique_size-1;
			ll partition = node_size/r;

			ll ciel_partition = partition;
			if(node_size%r) ciel_partition++;

			return 0.5*(node_size*node_size - ((node_size%r)*ciel_partition*ciel_partition) - ((r - (node_size%r))*partition*partition));
		}


		/*
		 * This method checks if the given graph does not have a clique of a given size.
		 *
		 * @param node_size: number of nodes in the graph.
		 * @param edge_size: number of edges in the graph.
		 * @param clique_size: size of clique.
		 * @return bool: the method returns true if the graph can't have the clique
		 * 				 of given size.
		 */
		bool does_not_have_clique(ll node_size, ll edge_size, ll clique_size) {
			return edge_size <= get_max_edges_for_clique_free_graph(node_size, clique_size);
		}


		/*
		 * This method returns the lower bound on the largest clique in a graph.
		 * The method runs in O(log(node_size))
		 * NOTE: The method assumes that the graph has at least one edge.
		 *
		 * @param nodes_size: the number of nodes in the graph.
		 * @param edge_size: the number of edges in the graph.
		 * @return ll: the lower bound on the largest clique.
		 */
		ll get_minimum_largest_clique(ll node_size, ll edge_size) {
			ll start = 2, end = node_size;
			while(1) {
				if(end-start <= 1) {
					if(does_not_have_clique(node_size, edge_size, end))
						return start;
					else
						return end;
				}

				ll mid = (start+end)/2;
				if(does_not_have_clique(node_size, edge_size, mid))
					end = mid - 1;
				else
					start = mid;
			}
		}
} clique;

int main() {	
	int t = 1;
	sd(t);
 
	rep(i,1,t) {
		ll n, m;
		cin>>n>>m;
		cout<<clique.get_minimum_largest_clique(n, m)<<endl;;
	}
	return 0;
}
