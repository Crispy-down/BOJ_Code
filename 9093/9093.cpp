#include <iostream>
#include <stack>
#include <string>

using namespace std;

int T;
stack <char> s;
stack <string> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string temp;
    string result;
    int point = 0;

    cin >> T;
    cin.ignore(); // cin after getline => clear buffer (or "\n" goes to buffer)

    for(int i = 0;i<T;i++) {
        getline(cin,temp);
        
        for(int p = 0;p<temp.length();p++) {
            s.push(temp[p]); 
        }

        while(!s.empty()) {
            result += s.top(); // word reverse sentence
            s.pop();
        }

        for(int k = 0;k<result.length();k++) {
            if(isspace(result[k]) != 0) { //char is empty?(empty => !0)
                st.push(result.substr(point,k-point)); //slice (start,length)
                point = k+1; //pointer move
            }
        }
        st.push(result.substr(point)); //last word push
        result = "";
        point = 0;

        while(!st.empty()) {
            cout << st.top() << " "; //sentence reverse
            st.pop();
        } 

        cout << "\n";
    }

    return 0;
}

// first => word reverse = stack use
// second => sentence reverse = stack use
