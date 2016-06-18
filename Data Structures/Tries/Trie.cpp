/*
 * Author: Adarsh Pugalia
 * Problem: http://codeforces.com/contest/455/problem/B
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

/*
 * This class implements the node of a trie.
 * 
 * @data ch: the character stored in the current node.
 * @data child[]: the pointers to possible 26 child of the node.
 * @data prefixes: the number of prefixes that end at this node.
 * @data is_word: boolean to check if the word ending at this node is present.
 * @data is_leaf: boolean to check if this is a leaf node.
 */
class Node {
	public:
		char ch;
		Node* child[26];
		int prefixes;
		bool is_word, is_leaf;

		Node() {
			ch = '.';
			rep(i,0,25) child[i] = NULL;
			prefixes = 0;
			is_word = 0;
			is_leaf = 1;
		}
};


/*
 * This class implements the data structure trie.
 *
 * @data root: the root node of the trie.
 *
 * NOTE: The root node does not store any character. It is just
 * the parent of all the first letter of the words in the trie.
 */
class Trie {
	public:
		Node *root;

		/* constructor. */
		Trie() {
			root = new Node();
		}

		/* 
		 * This method inserts the word in the trie recursively.
		 * @param cur_node: pointer to the current node where character is to be inserted.
		 * @param: pos: the position of index of the string to be inserted.
		 * @param s: the string to be inserted.
		 */
		void insert(Node *cur_node, int pos, string s) {
			cur_node->ch = s[pos];
			cur_node->prefixes++;
			pos++;

			if(pos<s.length()) {
				if(cur_node->child[s[pos]-'a']==NULL) {
					cur_node->child[s[pos]-'a'] = new Node();
					cur_node->is_leaf = 0;
				}

				insert(cur_node->child[s[pos]-'a'], pos, s);
			}
			else
				cur_node->is_word = 1;
		}


		/* This method is used to insert a string into the trie. */
		void insert(string s) {
			if(root->child[s[0]-'a']==NULL) {
				root->child[s[0]-'a'] = new Node();
				root->is_leaf = 0;
			}


			insert(root->child[s[0]-'a'], 0, s);
		}


		/*
	     * This method performs dfs on the trie recursively.
	     * @param cur_node: current node of the trie.
	     * @param s: string formed while reaching this node.
	     */
		void dfs(Node *cur_node, string s) {
			/* s now has the word formed from root to this node. */
			s += cur_node->ch;

			if(cur_node->is_leaf) {
				return;
			}

			rep(i,0,25) {
				if(cur_node->child[i]!=NULL) {
					dfs(cur_node->child[i], s);
				}
			}
		}


		/* This method is used to perfrom the dfs on the trie. */
		void dfs() {
			rep(i,0,25) {
				if(root->child[i]!=NULL) {
					dfs(root->child[i], "");
				}
			}
		}
}trie;

int main() {
	return 0;
}
