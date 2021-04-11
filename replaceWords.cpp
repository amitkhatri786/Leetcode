#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct t{
    struct t *next[26];
    int is_end;
};
typedef struct t TRIE;
TRIE *root;


TRIE *get_tri_node()
{
    int i;
    TRIE *temp = new TRIE();
    for(i=0;i<26;i++)
        temp->next[i] = NULL;
    temp->is_end = 0;
    return(temp);
}

void insert_in_trie(string w)
{
    int len = w.length();
    int index;
    TRIE *temp = root;
    for(int i= 0;i<len;i++) {
        index = w[i] - 'a';
        if(!temp->next[index])
            temp->next[index] = get_tri_node();
        temp = temp->next[index];
    }
    temp->is_end = 1;
}
int search_in_trie(string s,string &t)
{
    int index;
    TRIE *temp = root;
    string x;
    int len = s.length();
    for(int i=0;i<len;i++){
        index = s[i] - 'a';
        if(!temp->next[index])
            return 0;
        temp = temp->next[index];
        t = t + s[i];
        if(temp->is_end)
            return 1;
    }
    if(!temp->is_end)
        return 0;
    else {
        return 1;
    }
}
string replaceWords(vector<string> &dictionary, string sentence)
{
    string res;
    string temp1;
    
    root = get_tri_node();
    for(int i=0;i<dictionary.size();i++)
        insert_in_trie(dictionary[i]);
    for(int i =0;i<sentence.length();i++) {
        if(sentence[i] == ' '){
            string temp;
            if(search_in_trie(temp1,temp)) {
                res = res +  temp + sentence[i];
                temp1.erase();
            } else{
                res = res + temp1 + sentence[i];
                temp1.erase();
            }
        }else{
            temp1 += sentence[i];
        }
    }
    string temp;
    if(search_in_trie(temp1,temp)) {
                res = res +  temp;
                temp1.erase();
            } else{
                res = res + temp1;
                temp1.erase();
            }
    return res;
}

int main()
{
    vector <string> dic;
    string sent;
    // dic.push_back("a");
    // dic.push_back("aa");
    // dic.push_back("aaa");
    // dic.push_back("aaaa");
    dic.push_back("cat");
    dic.push_back("bat");
    dic.push_back("rat");
    //sent = {"a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"};
    sent = {"the cattle was rattled by the battery"};
    cout<<replaceWords(dic,sent)<<endl;
    return(0);
}
