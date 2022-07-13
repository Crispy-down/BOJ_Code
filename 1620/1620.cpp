#include <iostream>
#include <cctype> // isdigit
#include <map>
#include <string>

using namespace std;

map <string,int> m;

string namy[100001];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;
    string name;

    for(int i = 1;i<N+1;i++) {
        cin >> name;
        namy[i] = name;
        m.insert({name,i});
    }

    string command;

    for(int i = 0;i<M;i++) {
        cin >> command;
        if(isdigit(command[0]) != 0) { // command is value
            cout << namy[stoi(command)] << '\n';
        }
        else { // command is key
            auto item = m.find(command);
            cout << item->second << '\n';
        }
    }

    return 0;
}