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

#define max_node_size 1000005
#define Edge pair<int, ll>
/*
 * This class implements a node in the tree.
 *
 * @data index:  index of the node in the tree.
 * @data parent: parent of the node in the tree.
 * @data edges:  the edges from this node in the tree. The edges are stored as a vector
 *               of pair<int, ll>, the first being the index of the node to which there 
 *               is an edge, the second being the cost of the edge. 
 */
class Node {
	public:
		int index;
		int parent;
		vector<Edge > edges;


		/* constructor. */
		Node() { parent = -1; }
		inline int get_parent() { return parent; }
		inline void set_parent(int p) {	parent = p; }
};


class Tree {
	public:
		int node_size, root;
		Node nodes[max_node_size];

		Tree() { root = 1; }
		int get_node_size() { return node_size; }
		void set_node_size(int n) { node_size = n; }

		void add_edge(int a, int b, int c) { nodes[a].edges.pb(mp(b, c)); nodes[b].edges.pb(mp(a, c)); }
		void add_edge(int a, int b) { add_edge(a, b, 1); }


		int dfs(int node, int parent) {
			nodes[node].set_parent(parent);
			rep(i,0,sz(nodes[node].edges)) {
				Edge edge = nodes[node].edges[i];
				if(edge.f!=parent) {
					dfs(edge.f, node);
				}
			}
		}
}tree;