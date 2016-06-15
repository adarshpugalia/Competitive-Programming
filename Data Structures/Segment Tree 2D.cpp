/*
 * Author: Adarsh Pugalia
 * Data structure: 2D segment tree.
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
#define max_size 1005
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
 
/* This method does modular exponentiation in log(n). */
ll mod_pow(ll n, ll p) {if(p==0)return 1; if(n<=1)return n;ll res = 1;while(p){if(p&1) res = mod(res*n);n = mod(n*n);p /= 2;} return res;}
 
double fgcd(double a, double b) { if(fabs(a)<fabs(b)) return fgcd(b, a); if(fabs(b)<GCD_EPS) return a; return fgcd(b, fmod(a,b)); }
 
/* This method compares whether two doubles are (almost) equal. */
bool db_db_cmp(double a, double b) { return (a+EPS>b && a-EPS<b); }
 
int scan_d(){ int ip=getchar_unlocked(), ret=0, flag = 1; for(; ip<'0' || ip>'9'; ip=getchar_unlocked())if(ip=='-'){flag=-1; ip=getchar_unlocked(); break;}for(; ip>='0' && ip<='9'; ip=getchar_unlocked())ret=ret*10+ip-'0'; return flag*ret;}
ll scan_ll(){int ip=getchar_unlocked(), flag = 1; ll ret = 0; for(; ip<'0'||ip>'9'; ip=getchar_unlocked())if(ip=='-'){flag=-1; ip=getchar_unlocked(); break;}for(; ip>='0' && ip<='9'; ip=getchar_unlocked())ret = ret*10+ip-'0'; return flag*ret;}
 
void print_d(int n){if(n<0){n=-n; putchar_unlocked('-');}int i=10; char output_buffer[10]; do{output_buffer[--i]=(n%10)+'0'; n/=10;}while(n); do{putchar_unlocked(output_buffer[i]);}while(++i<10);}
void print_ll(ll n){if(n<0){n=-n; putchar_unlocked('-');}int i=21; char output_buffer[21]; do{output_buffer[--i]=(n%10)+'0'; n/=10;}while(n); do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
 
using namespace std;
 
/*
 * This class implements a single node for a 2D Segment tree.
 * It stores the values for a single range.
 *
 * @data start: start cell (x,y) for the range.
 * @data end  : end cell (x,y) for the range.
 */
class Node2D {
	public:
		pii start, end;
		int val;
 
		Node2D() {
			start = mp(-1, -1), end = mp(-1, -1);
			val = 0;
		}
 
		Node2D(pii i, pii j) {
			start = i, end = j;
			val = 0;
		}
};
 
 
/*
 * This class implements the 2D segment tree.
 * @data n: the number of rows in the primary matrix.
 * @data m: the number of columns in the primary matrix.
 * @data ar: the primary matrix.
 * @data seg_tree: the segment tree.
 *
 * @method init: method to take the primary array as input and build the segment tree.
 * @method query:  method to query the segment tree.
 * @method update: method to update the segment tree.
 */
class SegmentTree2D {
	public:
		int n, m, ar[max_size][max_size];
		Node2D seg_tree[8*max_size*max_size];
 
		/* 
		 * This method takes the primary array as input and builds the segment tree.
		 *
		 * NOTE: This method takes as input the size of the primary array and the primary array both.
		 */
		void init() { int a, b; cin>>a>>b; init(a, b); }
 
 
		/* 
		 * This method takes the primary array as input and builds the segment tree.
		 * @data a, b: the number of rows and columns of the primary array.
		 */
		void init(int a, int b) { n = a; m = b; rep(i,1,n) rep(j,1,m) ar[i][j] = scan_d(); build_segment_tree(1, mp(1,1), mp(n,m)); }
 
 		
 		/*
 		 * This method builds the segment tree.
 		 * Use this method when taking the primary input matrix manually and not via init method.
 		 */
 		void build_segment_tree() {
 			build_segment_tree(1, mp(1,1), mp(n, m));
 		}


		/* 
		 * This method initalizes the base node responsible for only one primary index. 
		 * @data node: the index of the node in the segment tree.
		 * @data index: the index in the primary array for which the node is responsible.
		 */
		inline void init_base_node(int node, pii index) { seg_tree[node].val = ar[index.f][index.s];}
 
 

		/*
		 * This method merges child nodes to evaluate the parent node.
		 * @data up_left, up_right, down_left, down_right: the child nodes.
		 * @return Node2D: the merged parent node.
		 */
		inline Node2D merge_node(Node2D up_left, Node2D up_right, Node2D down_left, Node2D down_right) {
			Node2D ret;
			ret.val = max(up_left.val, max(up_right.val, max(down_left.val, down_right.val)));
			return ret;
		}
 
 
		void print_node(int node, pii start, pii end) {
			cout<<"Node2D: "<<node<<" Start: "<<start.f<<":"<<start.s<<" End: "<<end.f<<":"<<end.s<<" value: "<<seg_tree[node].val<<endl;
		}
 
 
		/*
		 * This method builds the initial segment tree from the primary array.
		 *
		 * NOTE: This method is called itself from init(), but if you are taking the input
		 * in the primary array maually, call this with (1, start index, end index of the primary array).
		 */
		void build_segment_tree(int node, pii start, pii end) {
			if(start>end)
				return;
 	
 			/* This assert is thrown if the size of seg tree is smaller than required. */
			assert(node<8*max_size*max_size);
			if(start==end) { init_base_node(node, start); return; }
 
			int mid_x = (start.f+end.f)/2;
			int mid_y = (start.s+end.s)/2;
 
			build_segment_tree(4*node-2, start, mp(mid_x, mid_y));
			build_segment_tree(4*node-1, mp(start.f, mid_y+1), mp(mid_x, end.s));
			build_segment_tree(4*node, mp(mid_x+1, start.s), mp(end.f, mid_y));
			build_segment_tree(4*node+1, mp(mid_x+1, mid_y+1), end);
 
			seg_tree[node] = merge_node(seg_tree[4*node-2], seg_tree[4*node-1], seg_tree[4*node], seg_tree[4*node+1]);
		}
 
 
		/* 
		 * This method queries the segment tree for the value for a given range.
		 */
		Node2D query(int node, pii start, pii end, pii q_start, pii q_end) {
			if(start>end)
				return Node2D();
 
			if(q_start.f>end.f || q_end.f<start.f || q_start.s>end.s || q_end.s<start.s)
				return Node2D();
 
			if(q_start.f<=start.f && q_start.s<=start.s && q_end.f>=end.f && q_end.s>=end.s) return seg_tree[node];
 
			int mid_x = (start.f+end.f)/2;
			int mid_y = (start.s+end.s)/2;
 
			Node2D up_left = query(4*node-2, start, mp(mid_x, mid_y), q_start, q_end);
			Node2D up_right = query(4*node-1, mp(start.f, mid_y+1), mp(mid_x, end.s), q_start, q_end);
			Node2D down_left = query(4*node, mp(mid_x+1, start.s), mp(end.f, mid_y), q_start, q_end);
			Node2D down_right = query(4*node+1, mp(mid_x+1, mid_y+1), end, q_start, q_end);
			return merge_node(up_left, up_right, down_left, down_right);
		}
 
 
		/*
		 * This method queries the segment tree for a given range.
		 * @data start: start index of the range.
		 * @data end: end index of the range.
		 */
		Node2D query(pii start, pii end) { return query(1, mp(1, 1), mp(n,m), start, end); }
 
 
		/* 
		 * This method prints the segment tree for a given range.
		 */
		void print_segment_tree(ll node, pii start, pii end) {
			if(start>end)
				return;
 
			if(start==end) {
				cout<<"Node2D: "<<node<<" Start: "<<start.f<<":"<<start.s<<" End: "<<end.f<<":"<<end.s<<" value: "<<seg_tree[node].val<<endl; return;
			}
 
			ll mid_x = (start.f+end.f)/2;
			ll mid_y = (start.s+end.s)/2;
 
			print_segment_tree(4*node-2, start, mp(mid_x, mid_y));
			print_segment_tree(4*node-1, mp(start.f, mid_y+1), mp(mid_x, end.s));
			print_segment_tree(4*node, mp(mid_x+1, start.s), mp(end.f, mid_y));
			print_segment_tree(4*node+1, mp(mid_x+1, mid_y+1), end);
			cout<<"Node2D: "<<node<<" Start: "<<start.f<<":"<<start.s<<" End: "<<end.f<<":"<<end.s<<" value: "<<seg_tree[node].val<<endl; return;
		}
 
 
		/* This method prints the segment tree. */
		void print_segment_tree() { print_segment_tree(1, mp(1, 1), mp(n, m)); }
}st;
 
 
void preprocess() {
}
 
 
void init() {
}

 
void solve(int test_case) {
	init();
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