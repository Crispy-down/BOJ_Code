#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string,string> table;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,findex;
    cin >> n >> m;
    cin.ignore();
    string str;
    string str_key,str_val;

    for(int i = 0;i<n;i++) {
        getline(cin,str);
        findex = str.find(" ",0);
        str_key = str.substr(0,findex);
        str_val = str.substr(findex+1); //parsing 굳이 할 필요 없음
        // cin >> s1; cin >> s2;(공백기준)
        table.insert(pair<string,string>(str_key,str_val));
    }

    string find_key;
    for(int i = 0;i<m;i++) {
        getline(cin,find_key);
        auto item = table.find(find_key);
        if(item != table.end()) {
            cout << item->second << '\n'; // == table[find_key]
        }
    }
}
