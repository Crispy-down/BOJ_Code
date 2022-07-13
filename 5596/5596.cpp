#include <iostream>

using namespace std;

int main() {
    int tmp;
    int minguk = 0;
    int manse = 0;
    for(int i = 0;i<4;i++) {
        cin >> tmp;
        minguk += tmp;
    }
    for(int i = 0;i<4;i++) {
        cin >> tmp;
        manse += tmp;
    }

    if(minguk == manse) {
        cout << minguk;
    }
    else if(minguk > manse) {
        cout << minguk;
    }
    else {
        cout << manse;
    }
    return 0;

}