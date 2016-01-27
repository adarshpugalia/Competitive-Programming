/*
 * Author: Adarsh Pugalia
 * ALgorithm : Longest Palindromic Subsequence of a string.
 */

#include <bits/stdc++.h>
 
#define ll long long int
#define llu long long int unsigned
#define vi vector <int>
#define vl vector <ll> 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector <pii >
#define vpll vector <pll >
 
 
#define f first
#define s second
 
#define sd(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)
#define slf(n) scanf("%lf", &n)
 
#define pd(n) printf("%d", n);
#define pl(n) printf("%lld", n);
#define ps printf(" ")
#define pe printf("\n")
 
#define rep(i,j,k) for(int i=j; i<=k; i++)
#define repd(i,j,k) for(int i=j; i>=k; i--)
 
#define sz(n) (int)n.size()-1
#define all(n) n.begin(), n.end()
 
#define pb push_back
#define pob pop_back
#define mp make_pair
 
#define max_size 3005
#define max_sieve_size 1000005
#define max_log 17
 
#define INF 1000000000000000000
#define MOD 1000000007
#define EPS 0.00000001
 
#define mod(a) ((a)%MOD)
#define swap(a, b) a += b, b = a-b, a -= b
 
using namespace std;

class LongestPalindromicSubsequence {
	public:
		string a;
		int lps[max_size][max_size];

		void init(string w) {
			a = w;
			memset(lps, -1, sizeof(lps));
		}

		int get_lps(int start, int end, string a) {
		if(end<start)
			return 0;

		if(end==start)
			return 1;

		if(lps[start][end]!=-1)
			return lps[start][end];

		int ret = 0;
		if(a[start]==a[end])
			ret = 2 + get_lps(start+1, end-1, a);

		ret = max(ret, get_lps(start+1, end, a));
		ret = max(ret, get_lps(start, end-1, a));

		lps[start][end] = ret;
		return ret;
	}
};

int main() {
	return 0;
}