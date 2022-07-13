#include <iostream>
using namespace std;

int facto(int &a,int &b) {
	int result = 1;
	for(int i = a; i > a-b;i--) {
		result *= i;
	}
	return result;
}
int facto2(int &a) {
	int result1 = 1;
	for(int p = 1;p < a+1;p++) {
		result1 *= p;
	}
	return result1;
}
 
int main() {
	int a,b = 0;
	cin >> a >> b;
	cout << facto(a,b)/facto2(b);
	return 0;
}