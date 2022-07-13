#include <iostream>
#include <map>
using namespace std;

map <char,pair<char,char>> tree; //tree => map 

// pre,in,postorder are showing node's order
void preorder(char node) {
    cout << node << "";
    if(tree[node].first != '.') {
        preorder(tree[node].first);
    }
    if(tree[node].second != '.') {
        preorder(tree[node].second);
    }
}

void inorder(char node) {
    if(tree[node].first != '.') {
        inorder(tree[node].first);
    }
    cout << node << "";
    if(tree[node].second != '.') {
        inorder(tree[node].second);
    }
}

void postorder(char node) {
    if(tree[node].first != '.') {
        postorder(tree[node].first);
    }
    if(tree[node].second != '.') {
        postorder(tree[node].second);
    }
    cout << node << "";
}


int main() {
    int N;
    cin >> N;
    char a,b,c; //tree[a].first = b tree[a].second = c (left/right node)
    for(int i = 0;i<N;i++) {
        cin >> a >> b >> c;
        tree[a] = make_pair(b,c); //tree node input
    }
    preorder('A');
    cout << endl;
    inorder('A');
    cout << endl;
    postorder('A');
}