#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <locale>
//#include <map>
using namespace std;


int main()
{
	locale loc;
	int num;
	cin >> num;

	vector<string> arr(num);

	for (auto& i: arr)
		cin >> i;

	sort(arr.begin(), arr.end(), [](string x, string y)
			{
				int min_len = (x.length() < y.length()) ? x.length() : y.length();
				for (int i=0; i<min_len; i++)
				{
					if (tolower(x[i]) < tolower(y[i]))
						return true;
					else if (tolower(x[i]) > tolower(y[i]))
						return false;
				}
				return (x.length() < y.length());
			});

	for (auto j: arr)
		cout << j << " ";
	cout << endl;

	
	return 0;
}
