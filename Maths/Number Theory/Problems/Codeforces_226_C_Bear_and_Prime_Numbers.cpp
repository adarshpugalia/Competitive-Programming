/*
 * Author: Adarsh Pugalia
 * Problem Link: http://codeforces.com/contest/385/problem/C
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
#define max_sieve_size 10000005
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

/* This function calculates primes upto the given max_sieve_size. */
int sieve[max_sieve_size];
int sum[max_sieve_size];
int c[max_sieve_size];

void calc_sieve()
{
    for(int i=0; i<max_sieve_size; i++)
        sieve[i] = 0;
 
    sieve[0] = sieve[1] = -1;
 
    for(int i=2; i<max_sieve_size; i++)
    {
    	sum[i] = sum[i-1];
        if(sieve[i]==0)
        {
            for(int j=i; j<max_sieve_size; j=j+i)
            {
                sieve[j]++;
                sum[i] += c[j];
            }
        }
    }
}


void preprocess() {
}


void init() {
}


void solve(int test_case) {
	init();

	int n;
	sd(n);

	rep(i,1,n) {
		int a;
		sd(a);
		c[a]++;
	}

	calc_sieve();

	sd(n);
	rep(i,1,n) {
		int a, b;
		sd(a), sd(b);

		if(a>10000000) {
			cout<<"0\n";
			continue;
		}

		a = max(a, 2);
		b = min(b, 10000000);

		cout<<sum[b] - sum[a-1]<<endl;
	}
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
