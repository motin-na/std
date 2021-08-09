#include <iostream>
using namespace std;

int main()
{
	double n, a, b, x, y; //a < b

	cin >> n >> a >> b >> x >> y;

	double max_disk, min_disk, pr_max_disk, pr_min_disk;

//	if (x > y)
//	{
//		max_disk = x;
//		min_disk = y;

//		pr_max_disk = a;
//		pr_min_disk = b;
//	}
//	else
//	{	
		max_disk = y;
		min_disk = x;

		pr_max_disk = b;
		pr_min_disk = a;
//	}

	if (n > pr_max_disk)
		cout << (1-max_disk/100)*n;
	else if (n > pr_min_disk)
		cout << (1-min_disk/100)*n;
	else
		cout << n;

	return 0;
}




