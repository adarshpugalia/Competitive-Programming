/*
 * Author: Adarsh Pugalia
 * Problem: http://codeforces.com/contest/650/problem/B
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

int n, a, b, t;
char word[600000];
int pre[600000], suf[600000];

class BinarySearch {
	public:
		bool check(int val, int idx) {
			if(val==0)
				return true;

			int t = idx+1;
			repd(i,val,1) {
				int temp = pre[i];
				int left = val - i;
				if(left) {
					temp += (i-1)*a;
					temp += suf[n-(left-1)];
				}

				t = min(t, temp);
				if(left) {
					temp = suf[n - (left-1)];
					temp += a*left;
					temp += pre[i];
					t = min(t, temp);
				}
			}

			if(t<=idx)
				return true;

			return false;
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

void preprocess() {
}


void init() {
}


void solve(int test_case) {
	init();

	cin>>n>>a>>b>>t;
	scanf("%s", word+1);

	pre[0] = suf[n+1] = 0;
	pre[1] = 1;
	if(word[1]=='w')
		pre[1] += b;

	rep(i,2,n) {
		pre[i] = pre[i-1] + a+1;
		if(word[i]=='w')
			pre[i] += b;
	}

	suf[n] = 1 + a;
	if(word[n]=='w')
		suf[n] += b;

	repd(i,n-1,2) {
		suf[i] = suf[i+1] + a + 1;
		if(word[i]=='w')
			suf[i] += b;
	}

	cout<<bs.bs_right(0, n, t)<<endl;
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
