/*
 * Author: Adarsh Pugalia
 * Problem Link: http://codeforces.com/contest/629/problem/D
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

map<int, ll> m2;

/*
 * This class performs coordinate compression on an input vector.
 */
template <class T>
class CoordinateCompression {
	public:
		set<T> s;
		map<T, int> m;

		vector<T> compress(vector<T> v) {
			s.clear(), m.clear();

			rep(i,0,sz(v)) {
				s.insert(v[i]);
			}

			int i = 0;
			iter(it, s) {
				m[*it] = i;
				i++;
			}

			rep(i,0,sz(v)) {
				m2[m[v[i]]+1] = v[i];
				v[i] = m[v[i]];
			}

			return v;
		}
};

CoordinateCompression<ll> cc;
vector<ll> v;

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
		 * This method initalizes the base node responsible for only one primary index. 
		 * @data node: the index of the node in the segment tree.
		 * @data index: the index in the primary array for which the node is responsible.
		 */
		inline void init_base_node(ll node, ll index) { seg_tree[node].val = m2[index]; }


		/*
		 * This method merges two nodes of the segment tree to create the parent node.
		 * @data left: the left child of the node.
		 * @data right: the right child of the node.
		 * @return Node: the merged parent node.
		 */
		inline Node merge_node(Node left, Node right) { Node ret; ret.val = max(left.val,right.val); return ret; }


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

ll ar[max_size], n;

void preprocess() {
}


void init() {
}


void solve(int test_case) {
	init();

	cin>>n;

	rep(i,1,n) {
		ll r, h;
		cin>>r>>h;

		ar[i] = r*r*h;
	}

	st.n = n;
	rep(i,1,n) {
		v.pb(ar[i]);
		st.ar[i] = ar[i];
	}

	v = cc.compress(v);

	ll maxi = 1;
	rep(i,0,n-1)
		maxi = max(maxi, v[i]+1);

	rep(i,1,n) {
		int index = v[i-1]+1;
		ll ret = 0;
		if(index>1) {
			ret = max(ret, st.query(1, index-1).val);
		}

		st.update(index, ret+m2[index]);
	}

	ll ret = st.query(1, maxi).val;
	double ans = ret;
	ans = ans*PI;
	printf("%0.9lf\n", ans);
}

int main() {
	preprocess();
	int t = 1;
	//sd(t);
 
	rep(i,1,t) {
		solve(i);
	}
	return 0;
}
