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

int root;
int ar[max_size];

bool comp(pair<pii, int> i, pair<pii, int> j) {
	if((i.f.f/root) == (j.f.f/root))
		return i.f.s<j.f.s;

	return (i.f.f/root) < (j.f.f/root);
}


class Mo {
	public:
		int n;
		vector<pair<pii, int> > queries;
		ll ans[max_size];


		void input_queries(int n_, int q) {
			n = n_;
			queries.clear();
			
			rep(i,1,q) {
				int a, b;
				sd(a); sd(b);

				queries.pb(mp(mp(a, b), i-1));
			}
		}


		void add(int index) {
		}


		void remove(int index) {
		}

		void solve() {
			root = pow(n, 0.5);
			sort(all(queries), comp);
			
			/*
			 * Take care of the starting left and right markers.
			 * If the array is 0-indexed make them 0 and 0.
			 */
			int current_left = 1, current_right = 1;
			rep(i,0,sz(queries)) {
				int l = queries[i].f.f, r = queries[i].f.s;

				while(current_right <= r) {
					add(current_right);
					current_right++;
				}

				while(current_right > r+1) {
					remove(current_right-1);
					current_right--;
				}

				while(current_left < l) {
					remove(current_left);
					current_left++;
				}
				while(current_left > l) {
					add(current_left-1);
					current_left--;
				}

				// update ans here for the query.
				// ans[queries[i].s] = 
			}
		}

		void print_answers() {
			rep(i,1,queries.size()) {
				cout<<ans[i-1]<<endl;
			}
		}
}mo;

void preprocess() {
}


void init() {
}


void solve(int test_case) {
	init();

	int n, q;
	cin>>n>>q;

	rep(i,1,n) {
		cin>>ar[i];
	}

	mo.input_queries(n, q);
	mo.solve();
	mo.print_answers();
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
