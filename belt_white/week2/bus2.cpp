#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
using namespace std;

vector<string> ReadStops(int num)
{
	vector<string> answ(num);

	for (auto& m: answ)
		cin >> m;

	return answ;
}

int main()
{
	map<vector<string>, int> buses;
	vector<string> stops_arg;


	int cmd_int;
	string arg_string;
	int size;

	int cmd_num;
	cin >> cmd_num;
	int num;
	
	for (int i=0; i<cmd_num; i++)
	{
		cin >> cmd_int;
		stops_arg = ReadStops(cmd_int);
		size = buses.size();

		if (buses.count(stops_arg) == 0)
		{
			cout << "New bus " << size+1 << endl;
			buses[stops_arg] = size+1;	
		}
		else
		{
			for (auto bus: buses)
			{
				if (bus.first == stops_arg)
				{
					cout << "Already exists for " << bus.second << endl;
					break;
				}
			}
		}

	}
	return 0;
}
