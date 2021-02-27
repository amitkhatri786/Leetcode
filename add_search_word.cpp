//211. Design Add and Search Words Data Structure

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<unordered_map>

using namespace std;

class WordDictionary {
	public:
		/** Initialize your data structure here. */
		unordered_map<int,vector<string>> word_map;
		WordDictionary() {
			word_map.clear();
		}

		void addWord(string word) {
			int n;
			n = word.length();
			word_map[n].push_back(word);
		}
		bool is_same(string w,string s) {
			if(w == s) 
				return true;
			for(int i=0;i<w.length();i++) {
				if(w[i] == '.')
					continue;
				if(w[i]!= s[i])
					return false;
			}
			return true;	
		}
		bool search(string word) {
			int n = word.length();
			if(word_map.find(n) != word_map.end()){
				auto temp = word_map[n];
				for(auto str: temp) {
					if(is_same(word,str)) 
						return true;
				}
				return false;
			} else
				return false;
		}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main()
{
	WordDictionary* obj = new WordDictionary();
	obj->addWord("bad");
	obj->addWord("dad");
	obj->addWord("mad");
	cout <<obj->search("pad") <<endl; // return False
	cout <<obj->search("bad") <<endl; // return True
	cout <<obj->search(".ad") <<endl; // return True
	cout <<obj->search("b..") <<endl; // return True
	return 0;
}
