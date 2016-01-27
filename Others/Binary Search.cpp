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
 
#define max_size 100005
#define max_sieve_size 1000005
#define max_log 17
 
#define INF 1000000000000000000
#define MOD 1000000007
#define EPS 0.00000001
 
#define mod(a) ((a)%MOD)
#define swap(a, b) a += b, b = a-b, a -= b
 
using namespace std;

class BinarySearch {
	public:
		bool check(int val, int idx) {
		}

		int bs_right(int start, int end, int idx) {
			if(end-start<=1) {
				if(check(end, idx))
					return end;

				if(check(start, idx))
					return start;

				return -1;
			}

			int mid = (start+end)/2;
			if(check(mid+1, idx))
				return bs_right(mid+1, end, idx);

			return bs_right(start, mid, idx);
		}

		int bs_left(int start, int end, int idx) {
			if(end-start<=1) {
				if(check(start, idx))
					return start;

				if(check(end, idx))
					return end;

				return -1;
			}

			int mid = (start+end)/2;
			if(check(mid, idx))
				return bs_left(start, mid, idx);

			return bs_left(mid+1, end, idx);
		}
}bs;

int main() {
	return 0;
}