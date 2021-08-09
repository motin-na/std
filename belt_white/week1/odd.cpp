#include <iostream>
using namespace std;

int main()
{
	int a, b;

	cin >> a >> b; //A <= B, A >= 1, B <= 30000

	if (a % 2 == 1)
		a++;

	if (b % 2 == 1)
		b--;

	for (int i = a; i <= b; i+=2)
		cout << i << " ";

	return 0;
}




