/*
 * Auhtor:       Adarsh Pugalia
 * Problem Link: https://www.codechef.com/problems/FIBQ
 * Tags:         Segment Tree, Fibonacci
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

ll ciel(double a) { ll ret = a; if(a-ret>EPS) ret++; return ret; }
ll gcd(ll a, ll b) { if(a<b)return gcd(b, a); if(a%b==0)return b; return gcd(b, a%b); }
ll pow(ll n, ll p) {if(p==0)return 1; if(n<=1)return n;ll res = 1;while(p){if(p&1) res = mod(res*n);n = mod(n*n);p /= 2;} return res;}

double fgcd(double a, double b) { if(fabs(a)<fabs(b)) return fgcd(b, a); if(fabs(b)<GCD_EPS) return a; return fgcd(b, fmod(a,b)); }

bool db_db_cmp(double a, double b) { return (a+EPS>b && a-EPS<b); }
 
using namespace std;

/* fast input output. */
inline int scan_d(){ int ip=getchar_unlocked(), ret=0, flag = 1; for(; ip<'0' || ip>'9'; ip=getchar_unlocked())if(ip=='-'){flag=-1; ip=getchar_unlocked(); break;}for(; ip>='0' && ip<='9'; ip=getchar_unlocked())ret=ret*10+ip-'0'; return flag*ret;}
inline ll scan_ll(){int ip=getchar_unlocked(), flag = 1; ll ret = 0; for(; ip<'0'||ip>'9'; ip=getchar_unlocked())if(ip=='-'){flag=-1; ip=getchar_unlocked(); break;}for(; ip>='0' && ip<='9'; ip=getchar_unlocked())ret = ret*10+ip-'0'; return flag*ret;}
 
inline void print_d(int n){if(n<0){n=-n; putchar_unlocked('-');}int i=10; char output_buffer[10]; do{output_buffer[--i]=(n%10)+'0'; n/=10;}while(n); do{putchar_unlocked(output_buffer[i]);}while(++i<10);}
inline void print_ll(ll n){if(n<0){n=-n; putchar_unlocked('-');}int i=21; char output_buffer[21]; do{output_buffer[--i]=(n%10)+'0'; n/=10;}while(n); do{putchar_unlocked(output_buffer[i]);}while(++i<21);}

unordered_map<ll, ll> fibo_map;
unordered_map<ll, ll>::iterator it;

ll get_fibo(ll n) {
	if(n<2) {
		return n;
	}

	if(n==2) { return 1; }

	it = fibo_map.find(n);
	if(it!=fibo_map.end())
		return it->s;

	ll left = n/2, right = n/2;
	if(n&1) left++;

	ll ret = mod(mod(get_fibo(left)*get_fibo(right+1)) + mod(get_fibo(left-1)*get_fibo(right)));
	fibo_map[n] = ret;
	return ret;
}


class Node {
	public:
		ll val, pre, succ;

		Node() { val = 0, pre = 0, succ = 0; }
		Node(ll v) { val = v; }

		friend ostream &operator<<(ostream &output, const Node &node) { output<<node.val<<" "<<node.pre<<" "<<node.succ; return output; }
};


class SegmentTree {
	public:
		ll n;
		ll ar[max_size];
		Node seg_tree[4*max_size];

		void init() {
			ll a;
			cin>>a;
			init(a);
		}

		void init(ll a) {
			n = a;
			rep(i,1,n) {
				ar[i] = scan_ll();
			}

			build_segment_tree(1, 1, n);
		}


		inline void init_base_node(ll node, ll index) {
			seg_tree[node].val = get_fibo(ar[index]);
			seg_tree[node].pre = get_fibo(ar[index]-1);
			seg_tree[node].succ = get_fibo(ar[index]+1);
		}


		inline Node merge_node(Node left, Node right) {
			Node ret;
			ret.val = mod(mod(left.val + right.val) + mod(mod(left.val*right.succ) + mod(left.pre*right.val)));
			ret.pre = mod(mod(left.pre + right.pre) + mod(mod(left.val*right.val) + mod(left.pre*right.pre)));
			ret.succ = mod(mod(left.succ + right.succ) + mod(mod(left.val*right.val) + mod(left.succ*right.succ))); 
			return ret;
		}


		void build_segment_tree(ll node, ll start, ll end) {
			if(start==end) { 
				init_base_node(node, start);
				return;
			}

			ll mid = (start+end)/2;
			build_segment_tree(2*node, start, mid);
			build_segment_tree(2*node+1, mid+1, end);
			seg_tree[node] = merge_node(seg_tree[2*node], seg_tree[2*node+1]);
		}


		Node query(ll node, ll start, ll end, ll x, ll y) {
			if(start==x && end==y)
				return seg_tree[node];

			ll mid = (start+end)/2;
			if(mid>=y)
				return query(2*node, start, mid, x, y);
			if(mid<x)
				return query(2*node+1, mid+1, end, x, y);

			Node left = query(2*node, start, mid, x, mid);
			Node right = query(2*node+1, mid+1, end, mid+1, y);
			return merge_node(left, right);
		}

		Node query(ll start, ll end) { return query(1, 1, n, start, end); }


		void update(ll node, ll start, ll end, ll index, ll val) {
			if(start==end) {
				ar[index] = val;
				init_base_node(node, index);
				return;
			}

			ll mid = (start+end)/2;
			if(mid>=index)
				update(2*node, start, mid, index, val);
			else
				update(2*node+1, mid+1, end, index, val);

			seg_tree[node] = merge_node(seg_tree[2*node], seg_tree[2*node+1]);
		}


		void update(ll index, ll val) { update(1, 1, n, index, val); }

		void print_segment_tree(ll node, ll start, ll end) {
			if(start==end) {
				cout<<"Node: "<<node<<" Start: "<<start<<" End: "<<end<<" ";
				cout<<seg_tree[node]<<endl;
				return;
			}

			ll mid = (start+end)/2;
			print_segment_tree(2*node, start, mid);
			print_segment_tree(2*node+1, mid+1, end);
			cout<<"Node: "<<node<<" Start: "<<start<<" End: "<<end<<" ";
			cout<<seg_tree[node]<<endl;
		}

		void print_segment_tree() {
			print_segment_tree(1, 1, n);
		}
}st;

int main() {
	ll n, m;
	n = scan_ll(), m = scan_ll();

	st.init(n);
	rep(i,1,m) {
		char ch;
		ll a, b;
		scanf("%c", &ch);
		a = scan_ll(); b = scan_ll();

		if(ch=='Q') {
			Node ret = st.query(a, b);
			print_ll(ret.val); pe;
		}
		else {
			st.update(a, b);
		}
	}

	return 0;
}