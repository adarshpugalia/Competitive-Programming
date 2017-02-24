#include <iostream>
#include <string.h>

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
#define max_size 200005
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

/*
 * This class implements the KMP algorithm.
 */
class KMP {
	public:
		string needle;
		int failure[max_size];
		

		void init(string n) {
			needle = n;
			buildFailureFunction();
		}


		/*
		 * This method builds the failure function.
		 * failure[i] gives the length of strict suffix of the prefix of length i,
		 * which is also a prefix of needle.
		 */
		void buildFailureFunction() {
			failure[0] = failure[1] = 0;

			rep(i,2,needle.length()) {
				int currentPartialMatch = failure[i-1];
				while(1) {
					if(needle[currentPartialMatch] == needle[i-1]) {
						failure[i] = currentPartialMatch+1;
						break;
					}

					if(currentPartialMatch == 0) {
						failure[i] = 0;
						break;
					}

					currentPartialMatch = failure[currentPartialMatch];
				}
			}
		}


		/*
		 * This method returns the indices in hayStack where it matches
		 * the needle.ss
		 */
		vector<int> getMatchings(string hayStack) {
			vector<int> ret;
			int currentMatch = 0;
			int hayStackIndex = 0;

			while(hayStackIndex < hayStack.length()) {
				if(hayStack[hayStackIndex] == needle[currentMatch]) {
					currentMatch++;
					hayStackIndex++;

					if(currentMatch == needle.length()) {
						ret.pb(hayStackIndex - needle.length());
					}

				} else {
					if(currentMatch == 0) {
						hayStackIndex++;
					} else {
						currentMatch = failure[currentMatch];
					}
				}
			}

			return ret;
		}
}kmp;


int main() {
	return 0;
}