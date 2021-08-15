#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
//#include <string>
//#include <map>
using namespace std;


int main()
{
	int num;
	cin >> num;

	vector<int> arr(num);
	for (int& i: arr)
		cin >> i;

	sort(arr.begin(), arr.end(), [](int x, int y)
			{
				return (abs(x) < abs(y));
			});

	for (int j: arr)
		cout << j << " ";
	cout << endl;

	
	return 0;
}
