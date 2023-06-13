#include <bits/stdc++.h>
using namespace std;

int N;
int start_M,start_D,finish_M,finish_D;
int ans;
tuple <int,int,int,int> flower[100005];

bool cmp(tuple <int,int,int,int> a, tuple <int,int,int,int> b) {
    if(get<0>(a) == get<0>(b)) {
        if(get<1>(a) == get<1>(b)) {
            if(get<2>(a) == get<2>(b)) {
                return get<3>(a) < get<3>(b);
            }
            return get<2>(a) < get<2>(b);
        }
        return get<1>(a) < get<1>(b);
    }
    return get<0>(a) < get<0>(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0;i<N;i++) {
        cin >> start_M >> start_D >> finish_M >> finish_D;
        flower[i] = {start_M,start_D,finish_M,finish_D};
    }

    sort(flower,flower + N,cmp);

    if(get<0>(flower[0]) >= 3 && get<1>(flower[0]) >= 2) {
        cout << 0;
        return 0;
    }



    // for(int i = 0;i<N;i++) {
    //     cout << get<0>(flower[i]) << " "  << get<1>(flower[i]) << " "  << get<2>(flower[i]) << " " <<  get<3>(flower[i]) << "\n";    
    // }






}
// �� ���� ���ִ� ������ ����� �ʹ�.
// N���� ���� ����.
// ���� ��� ���� �ؿ� �Ǿ ���� �ؿ� ����.
// �ϳ��� ���� �Ǵ� ���� ���� ���� ������ �ִ�.
// ex) 
// 5�� 8�� ��ȭ -> 6�� 13�� ��
// 6�� 13�Ϻ��� ���ķδ� ���� �� �� ����.
// 4 6 9 11���� 30�ϱ���.
// 1 3 5 7 8 10 12���� 31�ϱ���.
// 2���� 28�ϱ���.
// N���� �ɵ� �� 2���� ������ �����ϴ� ���� �����ϰ� �ʹ�.
// #1. ���ְ� ���� �����ϴ� ������ 3�� 1�Ϻ��� 11�� 30�ϱ��� ���� ���� �� ���� �̻� �Ǿ��ֵ��� �Ѵ�.
// #2. ������ ���� �����Ƿ� ������ �ɴ� �ɵ��� ���� ������ �����Ѵ�.
// N���� �ɵ� ��, �� �� ������ �����ϴ� ���� ������ ��, ������ �ɵ��� �ּ� ������ ����ض�.

// �ϳ��� ���� ���� ���� ��, ���� ���� ������ ��������
// �� ������ �ɵ� �� ���� ��� �Ǵ� ���� ������.(������� ����)
// ���� ������ 12�� 1���̸� ��.
// ��ȭ ������ �ּ� 3�� 1��.
// 3�� 1�Ϻ��� 11�� 30�ϱ��� �ϳ��� �� �Ǹ� �ȵ�.
// �ּ��� ������ �ɾ���ϱ� ������, ���� ���� ������ �ð����� ��ġ�� �ð��� �ִ�ȭ�� �Ǿ�� ���� ������ �ٰ���.

// �켱, �����ؾ��� (tuple)
// ��ȭ �ñ� �� ��������, ���ٸ� �� ��.
// 3�� �� �ϳ� �� ����, �̴� ���� �ñⰡ ���� ����� ������.
// �� ����, ���� �ñ� ���� �� ������ �ɵ� ��, 