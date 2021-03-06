/*
 * Author: 	Adarsh Pugalia
 *
 * Algorithm: 	Z Algorithm: For a given string s, it calculates the longest
 *			substring starting from each index, such that the substring
 *			is a prefix of the string.
 *
 * Complexity:	O(n)
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
#define plf(n) printf("%0.9lf\n", n);
#define ps printf(" ")
#define pe printf("\n")

/* loops */
#define rep(i,j,k) for(int i=j; i<=k; i++)
#define repd(i,j,k) for(int i=j; i>=k; i--)
#define iter(it, s) for(auto it=s.begin(), it!=s.end(); it++)

/* constraints. */ 
#define max_size 100005
#define max_sieve_size 1000005
#define max_log 17
#define INF 1000000000000000000
#define MOD 1000000007
#define EPS 0.00000001
#define mod(a) ((a)%MOD)
 
using namespace std;

class Z{
	public:
		int z[max_size];

		void init(string w){
			int l=0, r = 0;
			rep(i,1,(int)w.length()-1) {
				if(i>r) {
					l = r = i;
					while(r<w.length() && w[r]==w[r-l])
						r++;

					z[i] = r-l;
					r--;
				}
				else {
					int k = i-l;
					if(z[k]<r-i+1) {
						z[i] = z[k];
					}
					else {
						l = i;
						while(r<w.length() && w[r]==w[r-l])
							r++;
						z[i] = r-l;
						r--;
					}
				}
			}
		}
}z;

int main() {
	return 0;
}