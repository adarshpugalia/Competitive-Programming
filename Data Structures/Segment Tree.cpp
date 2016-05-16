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
 * This class implements the node of the segment tree.
 * @data val: the value to be stored in a node.
 */
class Node {
	public:
		ll val;

		/* constructors. */
		Node() { val = 0; }
		Node(ll v) { val = v; }

		/* overloading output operator. */
		friend ostream &operator<<(ostream &output, const Node &node) { output<<node.val; return output; }
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
		Node seg_tree[4*max_size];

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
		void init(ll a) { n = a; rep(i,1,n) ar[i] = scan_ll(); build_segment_tree(1, 1, n); }


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
		inline Node merge_node(Node left, Node right) { Node ret; ret.val = left.val + right.val; return ret; }


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
		Node query(ll node, ll start, ll end, ll x, ll y) {
			if(start==x && end==y) return seg_tree[node];

			ll mid = (start+end)/2;
			if(mid>=y) return query(2*node, start, mid, x, y);
			if(mid<x) return query(2*node+1, mid+1, end, x, y);

			Node left = query(2*node, start, mid, x, mid), right = query(2*node+1, mid+1, end, mid+1, y);
			return merge_node(left, right);
		}


		/*
		 * This method queries the segment tree for a given range.
		 * @data start: start index of the range.
		 * @data end: end index of the range.
		 */
		Node query(ll start, ll end) { return query(1, 1, n, start, end); }


		/* 
		 * This method updates the segment tree.
		 */
		void update(ll node, ll start, ll end, ll index, ll val) {
			if(start==end) { ar[index] = val; init_base_node(node, index); return; }

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

int main() {
	return 0;
}