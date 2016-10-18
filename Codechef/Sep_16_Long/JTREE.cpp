/*
 * Author: Adarsh Pugalia
 * Problem: https://www.codechef.com/problems/JTREE
 * Solution: Dfs with Segment Tree.
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

/*
 * This class implements the node of the segment tree.
 * @data val: the value to be stored in a node.
 */
class SNode {
	public:
		ll val;

		/* constructors. */
		SNode() { val = 0; }
		SNode(ll v) { val = v; }

		/* overloading output operator. */
		friend ostream &operator<<(ostream &output, const SNode &node) { output<<node.val; return output; }
};


/*
 * This class implements the segment tree.
 * @data n: the number of items in the primary array on which segment tree is built.
 * @data ar: the primary array on which segment tree is built.
 * @data seg_tree: the segment tree.
 *
 * @method init: method to take the primary array as input and build the segment tree.
 * @method query:  method to query the segment tree.
 * @method update: method to update the segment tree.
 */
class SegmentTree {
	public:
		ll n, ar[max_size];
		SNode seg_tree[4*max_size];

		/* 
		 * This method takes the primary array as input and builds the segment tree.
		 *
		 * NOTE: This method takes as input the size of the primary array and the primary array both.
		 */
		void init() { ll a; cin>>a; init(a); }


		/* 
		 * This method takes the primary array as input and builds the segment tree.
		 * @data a: the size of the primary array.
		 */
		//void init(ll a) { n = a; rep(i,1,n) sl(ar[i]); build_segment_tree(1, 1, n); }


		void init(ll a) {
			n = a;
			rep(i,0,4*n + 5) {
				seg_tree[i].val = 1e16;
			}
		}


		/* 
		 * This method initalizes the base node responsible for only one primary index. 
		 * @data node: the index of the node in the segment tree.
		 * @data index: the index in the primary array for which the node is responsible.
		 */
		inline void init_base_node(ll node, ll index) { seg_tree[node].val = ar[index]; }


		/*
		 * This method merges two nodes of the segment tree to create the parent node.
		 * @data left: the left child of the node.
		 * @data right: the right child of the node.
		 * @return Node: the merged parent node.
		 */
		inline SNode merge_node(SNode left, SNode right) { SNode ret; ret.val = min(left.val,right.val); return ret; }


		/*
		 * This method builds the initial segment tree from the primary array.
		 *
		 * NOTE: This method is called itself from init(), but if you are taking the input
		 * in the primary array maually, call this with (1, start index, end index of the primary array).
		 */
		void build_segment_tree(ll node, ll start, ll end) {
			if(start==end) { init_base_node(node, start); return; }

			ll mid = (start+end)/2;
			build_segment_tree(2*node, start, mid); build_segment_tree(2*node+1, mid+1, end);
			seg_tree[node] = merge_node(seg_tree[2*node], seg_tree[2*node+1]);
		}


		/* 
		 * This method queries the segment tree for the value for a given range.
		 */
		SNode query(ll node, ll start, ll end, ll x, ll y) {
			if(start==x && end==y) return seg_tree[node];

			ll mid = (start+end)/2;
			if(mid>=y) return query(2*node, start, mid, x, y);
			if(mid<x) return query(2*node+1, mid+1, end, x, y);

			SNode left = query(2*node, start, mid, x, mid), right = query(2*node+1, mid+1, end, mid+1, y);
			return merge_node(left, right);
		}


		/*
		 * This method queries the segment tree for a given range.
		 * @data start: start index of the range.
		 * @data end: end index of the range.
		 */
		SNode query(ll start, ll end) { return query(1, 1, n, start, end); }


		/* 
		 * This method updates the segment tree.
		 */
		void update(ll node, ll start, ll end, ll index, ll val) {
			if(start==end) { seg_tree[node].val = val; return; }

			ll mid = (start+end)/2;
			if(mid>=index) update(2*node, start, mid, index, val);
			else update(2*node+1, mid+1, end, index, val);
			seg_tree[node] = merge_node(seg_tree[2*node], seg_tree[2*node+1]);
		}


		/*
		 * This method updates the segment tree.
		 * @data index: the index of the primary array to be updated.
		 * @data val: the value to be updated with.
		 */
		void update(ll index, ll val) { update(1, 1, n, index, val); }


		/* 
		 * This method prints the segment tree for a given range.
		 */
		void print_segment_tree(ll node, ll start, ll end) {
			if(start==end) {
				cout<<"Node: "<<node<<" Start: "<<start<<" End: "<<end<<" value: "<<seg_tree[node]<<endl; return;
			}

			ll mid = (start+end)/2;
			print_segment_tree(2*node, start, mid); print_segment_tree(2*node+1, mid+1, end);
			cout<<"Node: "<<node<<" Start: "<<start<<" End: "<<end<<" value: "<<seg_tree[node]<<endl;
		}


		/* This method prints the segment tree. */
		void print_segment_tree() { print_segment_tree(1, 1, n); }
}st;

#define max_node_size 100005
#define Edge pair<int, ll>

int pos = 1;

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
		ll cost;


		/* constructor. */
		Node() {
			parent = -1;
		}

		void init() {
			parent = -1;
		}


		inline int get_parent() {
			return parent;
		}
 

		inline void set_parent(int p) {
			parent = p;
		}
};

vpii tickets[max_node_size];

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
		// Graph() { rep(i,0,max_node_size-1) { nodes[i].index = i; visited[i] = 0; } is_undirected = true; }
		// Graph(int n) { node_size = n; is_undirected = true; }
		// Graph(int n, ll m) { node_size = n; edge_size = m; is_undirected = true; }

		void init(int n, int m) {
			node_size = n, edge_size = m;
			is_undirected = true;
			rep(i,0,n)
				nodes[i].init();
		}


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
		void dfs(int current, int parent) {
			visited[current] = 1;

			if(current == 1) {
				nodes[current].cost = 0;
				st.update(pos, 0);
			} else {
				ll cur_cost = -1;
				rep(i,0,sz(tickets[current])) {
					ll start = max(pos - tickets[current][i].f, 1);
					ll temp = st.query(start, pos-1).val;

					if(cur_cost == -1 || cur_cost > temp + tickets[current][i].s) {
						cur_cost = temp + tickets[current][i].s;
					}
				}

				st.update(pos, cur_cost);
				nodes[current].cost = cur_cost;
			}

			pos++;
			rep(i,0,sz(nodes[current].edges)) {
				if(!visited[nodes[current].edges[i].f]) {
					dfs(nodes[current].edges[i].f, current);
				}
			}

			pos--;
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
} g;

int main() {
	int n, m;
	cin>>n>>m;

	g.init(n, n-1);

	for(int i=1; i<n; i++) {
		int a, b;
		cin>>a>>b;
		g.add_edge(a, b);
	}

	while(m--) {
		int v, k, w;
		cin>>v>>k>>w;

		tickets[v].pb(mp(k,w));
	}

	st.init(n);
	g.dfs(1, -1);

	cin>>m;
	while(m--) {
		int a;
		cin>>a;
		cout<<g.nodes[a].cost<<endl;
	}
	return 0;
} 