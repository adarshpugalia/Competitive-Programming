/*
 * Author: Adarsh Pugalia
 * Algorithm: Compute articulation points in O(n+m) time.
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
 * This class implements a node in the graph.
 *
 * @data index:  index of the node in the graph.
 * @data parent: parent of the node in the graph.
 * @data edges:  the edges from this node in the graph. The edges are stored as a vector
 *               of pair<int, ll>, the first being the index of the node to which there 
 *               is an edge, the second being the cost of the edge. 
 */
class Node {
	public:
		int index;
		int parent;
		vector<Edge > edges;


		/* constructor. */
		Node() {
			parent = -1;
		}


		inline int get_parent() {
			return parent;
		}
 

		inline void set_parent(int p) {
			parent = p;
		}
};


/* 
 * This class implements the graph.
 *
 * @data node_size:     the number of nodes in the graph.
 * @data edge_size:     the number of edges in the graph.
 * @data is_undirected: a boolean variable to check if the graph is undirected.
 * @data nodes:         an array of nodes in the graph.
 *
 * NOTE: The graph is set as undirected as default. For directed graph, call 
 * set_directed() before any operation on the graph object.
 */
class Graph {
	public:
		int node_size;
		ll edge_size;
		bool is_undirected, visited[max_node_size];
		Node nodes[max_node_size];


		/* constructor. */
		Graph() { rep(i,0,max_node_size-1) { nodes[i].index = i; visited[i] = 0; } is_undirected = true; }


		/* This method sets the graph as directed. */
		void set_directed() { is_undirected = false; }


		void clear_visited() { rep(i,1,node_size) visited[i] = 0; }


		/*
		 * This method adds an edge to the graph.
		 * @param from: the source node.
		 * @param to:   the destination node.
		 * @param cost: the cost of the edge.
		 * 
		 * NOTE: In case of undirected graphs, the method add the other edge too.
		 */ 
		void add_edge(int from, int to, ll cost) {
			nodes[from].edges.pb(mp(to, cost));
			if(is_undirected)
				nodes[to].edges.pb(mp(from, cost));
		}


		/*
		 * This method adds an edge to the graph.
		 * @param from: the source node.
		 * @param to:   the destination node.
		 * 
		 * NOTE: In case of undirected graphs, the method add the other edge too.
		 */ 
		void add_edge(int from, int to) {
			add_edge(from, to, 1);
		}


		/* This method performs dfs on the graph. */
		void dfs(int current) {
			visited[current] = 1;

			rep(i,0,size(nodes[current].edges)) {
				int to = nodes[current].edges[i].f;
				if(!visited[to]) {
					nodes[to].parent = current;
					dfs(to);
				}
			}
		}
} graph;

/*
 * This class implements the methods to find articulation points.
 * @data node_size: number of nodes in the graph.
 * @data visited[]: boolean array to check if the node is visited.
 * @data discovered[]: stors the time when the node was discovered.
 * @data low[]: stores the lowest discovered time of any node reachable from this node.
 * @data is_articulation_point[]: stores if the current node is an articulation point.
 *
 * NOTE: It acts on the 'graph' object defined above.
 */
class ArticulationPoints {
	public:
		int node_size, tick;
		int visited[max_node_size], discovered[max_node_size], low[max_node_size], is_articulation_point[max_node_size];
 
 		/* constructors */
		ArticulationPoints() {}
 
		ArticulationPoints(int n) {
			node_size = n;
			rep(i,1,n) {
				visited[i] = 0;
				discovered[i] = -1;
				low[i] = -1;
				is_articulation_point[i] = 0;
			}
		}
 
 
		void dfs(int current) {
			int child = 0;
			tick++;
 
			visited[current] = 1;
			discovered[current] = low[current] = tick;
 
			rep(i,0,sz(graph.nodes[current].edges)) {
				int to = graph.nodes[current].edges[i].f;
				if(!visited[to]) {
					child++;
					graph.nodes[to].set_parent(current);
					dfs(to);
					low[current] = min(low[current], low[to]);
 
					if(graph.nodes[current].get_parent()==-1 && child>1)
						is_articulation_point[current] = 1;
 
					if(graph.nodes[current].get_parent()>-1 && low[to]>=discovered[current])
						is_articulation_point[current] = 1;
				}
				else {
					if(to!=graph.nodes[current].get_parent()) {
						low[current] = min(low[current], discovered[to]);
					}
				}
			}
		}
 

 		/* This method computes the articulation points. */
		void compute_articulation_point() {
			tick = 0;
 
			rep(i,1,node_size) {
				if(!visited[i]) {
					dfs(i);
				}
			}
		}
}ap;


int main() {
	ap = ArticulationPoints(100);
	return 0;
}