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
		Graph(int n) { node_size = n; is_undirected = true; }
		Graph(int n, ll m) { node_size = n; edge_size = m; is_undirected = true; }


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


		/* This method performs recursive dfs on the graph. */
		void dfs(int current) {
			visited[current] = 1;

			rep(i,0,sz(nodes[current].edges)) {
				int to = nodes[current].edges[i].f;
				if(!visited[to]) {
					nodes[to].parent = current;
					dfs(to);
				}
			}
		}


		/*
		 * This method performs the bfs.
		 * @param start_node: node to start from.
		 * @param end_node: node to end.
		 * @return int: distance from start node to end node.
		 */
		int bfs(int start_node, int end_node) {
			queue<pii > q;
			q.push(mp(start_node, 0));
			visited[start_node] = 1;

			while(!q.empty()) {
				pii cur = q.front();
				q.pop();

				if(cur.f == end_node) return cur.s;

				rep(i,0,sz(nodes[cur.f].edges)) {
					int to = nodes[cur.f].edges[i].f;
					if(!visited[to]) {
						q.push(mp(to, cur.s+1));
						visited[to] = 1;
					}
				}
			}
		}


		/* This method converts the graph into its complement graph. */
		void complement_graph() {
			rep(i,1,node_size) {
				vector<bool> v(node_size+1, true);
				rep(j,0,sz(nodes[i].edges)) v[nodes[i].edges[j].f] = false;
				nodes[i].edges.clear();
				rep(j,1,i-1) if(v[j]) add_edge(i,j);
			}
		}


		/* overloading output operator. */
		friend ostream &operator<<(ostream &output, const Graph &g) { 
			output<<"Node Size: " << g.node_size << " Edge Size: " << g.edge_size<<endl; 
			rep(i,1,g.node_size)
				rep(j,0,sz(g.nodes[i].edges)) 
					output << "From: " << i << " To: " << g.nodes[i].edges[j].f << " Cost: " << g.nodes[i].edges[j].s << endl;
			return output; 
		}
}  