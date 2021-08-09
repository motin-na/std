#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

#define WORRY 0
#define QUIET 1
#define COME 2
#define WORRY_COUNT 3

void worry (vector<bool>& s, int a)
{
	s[a] = true;
}

void quiet (vector<bool>& s, int a)
{
	s[a] = false;
}

void come (vector<bool>& s, int a)
{
	s.resize(s.size() + a);
}

void worry_count (const vector<bool>& s)
{
//	cout << "Size: " << s.size() << endl;
	int cnt = 0;
	for (auto i: s)
		if (i)
			cnt++;

	cout << cnt << endl;
		
}

int main()
{
	vector<bool> s;

	int n;
	int arg_rd;

	string str;
	int str_int;


	cin >> n;

	for (int i=0; i<n; i++)
	{
		cin >> str;
		if (str == "WORRY")
			str_int = 0;
		else if (str == "QUIET")
			str_int = 1;
		else if (str == "COME")
			str_int = 2;
		else if (str == "WORRY_COUNT")
			str_int = 3;
		
		switch (str_int)
		{
			case WORRY:
			//	cout << "worry" << endl;
				cin >> arg_rd;
			//	cout << arg_rd << endl;
				worry(s, arg_rd);
			break;
			
			case QUIET:
			//	cout << "quiet" <<endl;
				cin >> arg_rd;
			//	cout << arg_rd << endl;
				quiet(s, arg_rd);
				
			break;

			case COME:
			//	cout << "come" << endl;
				cin >> arg_rd;
			//	cout << arg_rd << endl;
				come(s, arg_rd);
			break;

			case WORRY_COUNT:
			//	cout << "worry_count" << endl;
				worry_count(s);
			break;

			default: 
				cout << "ERROR" << endl;
				return 0;
		}
	}
	return 0;
}
