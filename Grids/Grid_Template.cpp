/*****************************************************************************************/
/*																		     			 */
/*  					Adarsh Pugalia 										 			 */
/*																			 			 */
/*****************************************************************************************/
 
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
#define max_size 505
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


/* Fast IO (does not work on codeforces) */
// int scan_d(){ int ip=getchar_unlocked(), ret=0, flag = 1; for(; ip<'0' || ip>'9'; ip=getchar_unlocked())if(ip=='-'){flag=-1; ip=getchar_unlocked(); break;}for(; ip>='0' && ip<='9'; ip=getchar_unlocked())ret=ret*10+ip-'0'; return flag*ret;}
// ll scan_ll(){int ip=getchar_unlocked(), flag = 1; ll ret = 0; for(; ip<'0'||ip>'9'; ip=getchar_unlocked())if(ip=='-'){flag=-1; ip=getchar_unlocked(); break;}for(; ip>='0' && ip<='9'; ip=getchar_unlocked())ret = ret*10+ip-'0'; return flag*ret;}
// void print_d(int n){if(n<0){n=-n; putchar_unlocked('-');}int i=10; char output_buffer[10]; do{output_buffer[--i]=(n%10)+'0'; n/=10;}while(n); do{putchar_unlocked(output_buffer[i]);}while(++i<10);}
// void print_ll(ll n){if(n<0){n=-n; putchar_unlocked('-');}int i=21; char output_buffer[21]; do{output_buffer[--i]=(n%10)+'0'; n/=10;}while(n); do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
/* End of fast IO. */ 

using namespace std;

class Grid {
	public:
		int n, m;
		pii LEFT, RIGHT, DOWN, UP;
		char grid[max_size][max_size];
		int vis[max_size][max_size];


		/*
		 * Constructor.
		 * It initilaizes the directions.
		 */
		Grid() { LEFT = mp(0, -1); RIGHT = mp(0, 1); UP = mp(-1, 0); DOWN = mp(1, 0); }


		/* This method takes the height, width, and grid as input from stdin. */
		void input() { cin>>n>>m; input(n, m); }


		/*
		 * This method takes the grid as input from stdin.
		 * @param a: height of the grid.
		 * @param b: width of the grid.
		 *
		 * NOTE: Change here in case of int grid.
		 */
		void input(int a, int b) { n = a, m = b; rep(i,1,n) { scanf("%s", grid[i]+1); } }


		/* This method checks if the cell is inside the grid. */
		bool is_inside(pii cell) { if(cell.f>0 && cell.f<=n && cell.s>0 && cell.s<=m) return true; return false; }


		/* 
		 * This method checks if you can move to a give cell.
		 * @param cell: the cell to move to.
		 */
		bool is_valid_to_move(pii cell) {
			if(grid[cell.f][cell.s]=='.' && vis[cell.f][cell.s]==0)
				return true;

			return false;
		}


		/*
		 * This method returns the next cell in the given direction.
		 * @param cur: the current cell.
		 * @param dir: the direction in which to move.
		 */
		pii get_next_cell(pii cur, pii dir) {
			return mp(cur.f+dir.f, cur.s+dir.s);
		}


		/*
		 * This method performs the dfs on the grid recursively.
		 * @param cur: the current cell.
		 * @param parent: the parent cell.
		 */
		void dfs(pii cur, pii parent) {
			vis[cur.f][cur.s] = 1;

			pii next_cell = get_next_cell(cur, LEFT);
			if(is_inside(next_cell) && is_valid_to_move(next_cell)) {
				dfs(next_cell, cur);
			}

			next_cell = get_next_cell(cur, RIGHT);
			if(is_inside(next_cell) && is_valid_to_move(next_cell)) {
				dfs(next_cell, cur);
			}

			next_cell = get_next_cell(cur, UP);
			if(is_inside(next_cell) && is_valid_to_move(next_cell)) {
				dfs(next_cell, cur);
			}

			next_cell = get_next_cell(cur, DOWN);
			if(is_inside(next_cell) && is_valid_to_move(next_cell)) {
				dfs(next_cell, cur);
			}
		}


		/*
		 * This method performs the dfs on the grid from a starting cell.
		 * @param start: the starting cell.
		 */
		void dfs(pii start) {
			rep(i,1,n) rep(j,1,m) vis[i][j] = 0;
			dfs(start, mp(-1, -1));
		}


		/* This method outputs the grid. */
		void output() {
			rep(i,1,n) {
				rep(j,1,m) {
					cout<<grid[i][j];
				}
				cout<<endl;
			}
		}
}grid;

int main() {
	return 0;
}