/*
 * Author: Adarsh Pugalia
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
#define max_size 1000005
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
 * This class computes a modular rolling hash on an array or a string.
 *
 * @data divisor     : the number you wish to take the mod with.
 * @data base        : the base of the number system used.
 * @data hashed_array: the array obtained after hashing.
 * @data sub_char    : the charachter you wish to substract each index in case of string hash.
 *					 : for ex. abc, you might want to substract each character with 'a' before hasing.
 *
 * NOTE: The class uses 1-based indexing for arrays and strings everywhere.
 */
class ModularHash {
	public:
		ll divisor, base, size;
		ll hashed_array[max_size];
		ll mul_array[max_size];
		char sub_char;

		Hash() { base = 10; }

		/* This method is used to set the divisor. */
		void set_divisor(ll div) { divisor = div; }
		
		/* This method is used to set the base. */
		void set_base(ll b) { base = b; }

		/* This method is used to set the subtraction character. */
		void set_sub_char(char ch) { sub_char = ch; }

		/*
		 * This method computes the hash on an array.
		 * @param n : the size of the array.
		 * @param ar: the array to compute the hash on.
		 */
		void compute_hash(ll n, ll ar[]) {
			size = n; hashed_array[0] = 0; mul_array[0] = 1;

			rep(i,1,n) {
				hashed_array[i] = (hashed_array[i-1]*base + ar[i])%divisor;
				mul_array[i] = (mul_array[i-1]*base)%divisor;
			}
		}


		/*
		 * This method computes the hash on a string.
		 */
		void compute_hash(string s) {
			size = s.length(); hashed_array[0] = 0; mul_array[0] = 1;

			rep(i,1,size) {
				hashed_array[i] = (hashed_array[i-1]*base + (s[i-1]-sub_char))%divisor;
				mul_array[i] = (mul_array[i-1]*base)%divisor;
			}
		}

		/*
		 * This method computes the hash of a range.
		 * @param start: start index of the range.
		 * @param end  : end index of the range.
		 */
		ll get_hash(int start, int end) {
			ll ret = hashed_array[end];
			ret = (ret - ((hashed_array[start-1]*mul_array[end-start+1])%divisor) + divisor)%divisor;
			return ret;
		}
};

int main() {
	return 0;
}