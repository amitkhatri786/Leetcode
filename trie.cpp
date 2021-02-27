#include<iostream>
#include<string>

using namespace std;

//Implement Trie (Prefix Tree)
//208. Implement Trie (Prefix Tree)

struct t{
	struct t *next[26];
	int is_end;
};
typedef struct t TRIE;

class Trie {
	public:
		/** Initialize your data structure here. */
		TRIE *root;
		Trie() {
			TRIE *node;
			node = get_tri_node();
			root = node;
		}

		/** Inserts a word into the trie. */
		void insert(string word) {
			int i;
			TRIE *temp = root;
			int index;
			for(i=0;i<word.length();i++) {
				index = word[i] - 'a';
				if(!temp->next[index])
					temp->next[index] = get_tri_node();
				temp = temp->next[index];
			}
			temp->is_end = 1;
		}

		/** Returns if the word is in the trie. */
		bool search(string word) {
			int i;
			TRIE *temp = root;
			int index;
			for(i=0;i<word.length();i++) {
				index = word[i] - 'a';
				if(!temp->next[index])
					return false;
				temp = temp->next[index];
			}
			if(temp->is_end)
				return true;
			return false;
		}

		/** Returns if there is any word in the trie that starts with the given prefix. */
		bool startsWith(string prefix) {
			int i,index;
			TRIE *temp = root;
			for(i=0;i<prefix.length();i++){
				index = prefix[i] - 'a';
				if(!temp->next[index])
					return false;
				temp = temp->next[index];
			}
			if(temp)
				return true;
			return false;
		}
		TRIE *get_tri_node()
		{
			int i;
			TRIE *temp = new TRIE;
			for(i=0;i<26;i++)
				temp->next[i] = NULL;
			temp->is_end = 0;
			return (temp);
		}
};

int main()
{
	Trie *obj = new Trie();
	obj->insert("amit");
	obj->insert("rahul");
	cout << obj->search("amit") << endl;
	cout <<obj->search("amitk") << endl;
	return(0);
}
