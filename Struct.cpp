#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll ;

const ll inf = 1e10 + 7;
const int maxn = 1e5 + 10;
const int maxq = 1e3 + 10;
const int alf = 26;
const ll dlm = 1e9 + 7;
const int del = 998244353 ;
const int eps = 1e-7 ;

struct Point {
    int x, y;

};

int f(int &x) {
    x++;
    return x;
}

//use const if you dont want it to change
void g(Point &p) {
    p.x = 10;
}

struct Node {
    int x;
    Node *next, *last;
};

struct trieNode {
    int cnt_end;
    trieNode *childs[30];
};
trieNode *beg_trie;

struct bignum {
    string s;
    //operator * (bignum & y)

};

Node *beg;
void add(int in) {
    Node *tmp = beg;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new Node();
    tmp->next->x = in;
}
void out() {
    Node * tmp = beg;
    while(tmp != NULL) {
        cout<<tmp->x<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

void add_trie(trieNode *cur, string s, int idx) {
    if(idx == s.size()) {
        cur->cnt_end++;
        return;
    }
    if(cur->childs[s[idx]-'a'] != NULL) {
        add_trie(cur->childs[s[idx]-'a'], s, idx+1);
    }
    else {
        cur->childs[s[idx]-'a'] = new trieNode();
         add_trie(cur->childs[s[idx]-'a'], s, idx+1);
    }
}

void dfs(trieNode *cur, string s) {
    if(cur == NULL)
        return;

    if(cur->cnt_end != 0) {
        cout<<s<<" "<<cur->cnt_end<<endl;
    }
    for(int i = 0 ; i < 26 ; i++)
        dfs(cur->childs[i], s+char(i+'a'));
}

int main()
{

    ios::sync_with_stdio(false);cin.tie(0);
    beg_trie = new trieNode();
    add_trie(beg_trie, "hello", 0);
    add_trie(beg_trie, "hello", 0);
    add_trie(beg_trie, "asd", 0);
    add_trie(beg_trie, "bye", 0);
    add_trie(beg_trie, "hellp", 0);
    dfs(beg_trie, "");
    /*beg = new Node();
    beg->x = 1;
    out();
    add(5);
    add(2);
    add(16);
    add(8);
    out();*/

    /*int x;
    x = 2;
    int *y;
    *y = x;//y = &x
    x = 5;
    cout<<x<<" "<<*y<<endl;*/
    //int x = 10;
    //cout<<x+f(x)<<endl;
    /*Point p;
    p.x = 1;
    p.y = 2;
    g(p);
    cout<<p.x<<endl;*/
    /*Node *linked_list;
    linked_list = new Node();
    cout<<linked_list->x<<endl;*/


}
