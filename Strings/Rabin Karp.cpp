#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cassert>
#include <string.h>
 
#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define vpii vector <pair<int, int> >
#define vpll vector <pair<ll, ll> >
#define pll pair<ll, ll>
 
#define f first
#define s second
 
#define sd(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)
 
#define pb push_back
#define pob pop_back
 
#define max_size 200005
#define max_capacity INT_MAX
#define max_string_size 1000
#define max_node_size 340
#define max_power 26
#define max_sieve_size 5000003
 
#define MOD 100000000
 
using namespace std;

/* string template. */

string to_lower(string word)
{
	for(ll i=0; i<word.length(); i++)
		word[i] = tolower(word[i]);

	return word;
}

/* string template ends. */

/* This function calcluates the pth power of a number n modula given mod. */
ll mod_pow(ll n, ll p, ll mod)
{
	ll res = 1;
	while(p)
	{
		if(p&1)
			res = (res*n)%mod;
 
		n = (n*n)%mod;
 
		p /= 2;
	}
 
	return res;
}
 
 
/* This function calculates the modular inverse of the given number n. */
ll mod_inv(ll n, ll mod)
{
	return mod_pow(n, mod-2, mod);
}
 
 
 
/* This function performs the division modulo prime. */
ll mod_divison(ll dividend, ll divisor, ll mod)
{
	return (dividend*mod_inv(divisor, mod))%mod;
}

class RabinKarp
{
	public:
		/*
		 * Use these primes in case primes not given, prime1 = 9999991, prime2 = 1000000007 
		 */
		ll prime1, prime2;
		int alphabet_size, length;
		pll pre[max_size], suf[max_size], mul[max_size];

		void init(ll i, ll j, ll k)
		{
			prime1 = i;
			prime2 = j;
			alphabet_size = k;
		}

		void init(ll k)
		{
			alphabet_size = k;
			prime1 = 9999991;
			prime2 = 1000000007;
		}

		void generate_prefix_hash(string word)
		{
			pre[0] = make_pair(0, 0);
			mul[0] = make_pair(1, 1);

			for(int i=1; i<=word.length(); i++)
			{
				pre[i].f = ((pre[i-1].f*alphabet_size)%prime1 + word[i-1])%prime1;
				pre[i].s = ((pre[i-1].s*alphabet_size)%prime2 + word[i-1])%prime2;

				mul[i].f = (mul[i-1].f*alphabet_size)%prime1;
				mul[i].s = (mul[i-1].s*alphabet_size)%prime2;
			}
		}

		void generate_suffix_hash(string word)
		{
			suf[word.length()+1] = make_pair(0, 0);
			for(int i=word.length(); i>0; i--)
			{
				suf[i].f = ((suf[i+1].f*alphabet_size)%prime1 + (word[i-1]))%prime1;
				suf[i].s = ((suf[i+1].s*alphabet_size)%prime2 + (word[i-1]))%prime2;
			}	
		}


		/* 
		 * This function checks if the substring s[i..j] is a palindrome.
		 * The string is 1-indexed.
		 */
		bool is_palindrome(ll i, ll j)
		{
			ll k = j-i+1;

			ll half_hash1 = ((pre[i+(k/2)-1].f - pre[i-1].f*mul[k/2].f)%prime1+prime1)%prime1;
			ll half_hash2 = ((suf[i+((k+1)/2)].f - suf[i+k].f*mul[k/2].f)%prime1+prime1)%prime1;

			if(half_hash1==half_hash2)
			{
				half_hash1 = ((pre[i+k/2-1].s - pre[i-1].s*mul[k/2].s)%prime2+prime2)%prime2;
				half_hash2 = ((suf[i+((k+1)/2)].s - suf[i+k].s*mul[k/2].s)%prime2+prime2)%prime2;

				if(half_hash1==half_hash2)
					return true;
			}

			return false;
		}


		/*
		 * This method returns the hash of a substring s[i...j]
		 *
		 * NOTE: This method is 1-indexed.
		 */
		pll get_hash(int i, int j)
		{
			ll hash1 = ((pre[j].f - pre[i-1].f*mul[j-i+1].f)%prime1+prime1)%prime1;
			ll hash2 = ((pre[j].s - pre[i-1].s*mul[j-i+1].s)%prime2+prime2)%prime2;

			return make_pair(hash1, hash2);
		}


		/*
		 * This method returns the hash of the two substrings concatenated.
		 *
		 * NOTE: This method is 1-indexed.
		 */
		pll get_merged_hash(int start1, int end1, int start2, int end2) {
			pll ret, hash1, hash2;
			hash1 = get_hash(start1, end1);
			hash2 = get_hash(start2, end2);
			
			ret.f = ((hash1.f*mul[end2-start2+1].f)%prime1 + hash2.f)%prime1;
			ret.s = ((hash1.s*mul[end2-start2+1].s)%prime2 + hash2.s)%prime2;
			return ret;
		}

		vl search(string text, string pattern)
		{
			vl ret;

			ll pattern_hash1=0, pattern_hash2=0;
			ll text_hash1=0, text_hash2=0;
			ll mul1=1, mul2=1;

			for(ll i=0; i<pattern.length(); i++)
			{
				pattern_hash1 = ((pattern_hash1*alphabet_size)%prime1 + pattern[i])%prime1;
				pattern_hash2 = ((pattern_hash2*alphabet_size)%prime2 + pattern[i])%prime2;

				text_hash1 = ((text_hash1*alphabet_size)%prime1 + text[i])%prime1;
				text_hash2 = ((text_hash2*alphabet_size)%prime2 + text[i])%prime2;

				mul1 = (mul1*alphabet_size)%prime1;
				mul2 = (mul2*alphabet_size)%prime2;
			}

			mul1 = mod_divison(mul1, alphabet_size, prime1);
			mul2 = mod_divison(mul2, alphabet_size, prime2);

			if(pattern_hash1==text_hash1 && pattern_hash2==text_hash2)
				ret.pb(0);

			for(ll i=pattern.length(); i<text.size(); i++)
			{
				text_hash1 = (text_hash1 - (text[i-pattern.length()]*mul1)%prime1 + prime1)%prime1;
				text_hash1 = (text_hash1*alphabet_size)%prime1;
				text_hash1 = (text_hash1 + text[i])%prime1;

				text_hash2 = (text_hash2 - (text[i-pattern.length()]*mul2)%prime2 + prime2)%prime2;
				text_hash2 = (text_hash2*alphabet_size)%prime2;
				text_hash2 = (text_hash2 + text[i])%prime2;

				if(pattern_hash1==text_hash1 && pattern_hash2==text_hash2)
					ret.pb(i-pattern.length()+1);
			}

			return ret;
		}

}rabin_karp1;
