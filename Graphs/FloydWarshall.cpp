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

#define MAX_NODE_SIZE 500

/*
 * This class implements the floyd warshall algorithm
 * for computing the all pair shortest paths.
 *
 * @data node_size: the size of the graph.
 * @data cost: array that stores the distance between
 *			   each pair of node.	
 */
class FloydWarshall {
	public:
		ll node_size;
		ll cost[MAX_NODE_SIZE][MAX_NODE_SIZE];

		/* constructors. */
		FloydWarshall() {};
		FloydWarshall(ll n, ll m) {
			node_size = n;
			rep(i,1,n) rep(j,1,n) cost[i][j] = -1;
		}	


		/* This method adds an edge in the graph. */
		void addEdge(int a, int b, ll c) {
			cost[a][b] = c;
		}


		/* 
		 * This method computes the shortest paths. 
		 * NOTE: The distance between unreachable pair of nodes are -1.
		 */
		void computeShortestPaths() {
			rep(k,1,node_size) {
				rep(i,1,node_size) {
					rep(j,1,node_size) {
						if(cost[i][k] != -1 && cost[k][j] != -1 && (cost[i][j] == -1 || cost[i][j] > cost[i][k] + cost[k][j]))
							cost[i][j] = cost[i][k] + cost[k][j];
					}
				}
			}
		}


		/* 
		 * This method returns the shortest path between two nodes.
		 * @param a: start node.
		 * @param b: end node. 
		 */
		ll getShortestPath(int a, int b) {
			return cost[a][b];
		}
}fw;

int main() {
	return 0;
}
