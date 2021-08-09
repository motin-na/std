#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
using namespace std;

#define ERROR -1
#define NEW_BUS 0
#define BUSES_FOR_STOP 1
#define STOPS_FOR_BUS 2
#define ALL_BUSES 3

void WriteVectorEx(const vector<string>& vec, string bus_ex)
{
	int k = 0;
	for (auto i: vec)
		if (i != bus_ex)
		{
			k++;
			cout << i << " ";
		}
	if (k == 0)
		cout << "no interchange";
	cout << endl;
}

int ParseCMD(string cmd)
{
	if (cmd == "NEW_BUS")
		return NEW_BUS;
	else if (cmd == "BUSES_FOR_STOP")
		return BUSES_FOR_STOP;
	else if (cmd == "STOPS_FOR_BUS")
		return STOPS_FOR_BUS;
	else if (cmd == "ALL_BUSES")
		return ALL_BUSES;

	return ERROR;
}

vector<string> ReadStops(int num)
{
	vector<string> answ(num);

	for (auto& m: answ)
		cin >> m;

	return answ;
}

void NewBus(map<string, vector<string>>& stops, map<string, vector<string>>& buses, string bus, const vector<string>& stops_arg)
{
	buses[bus] = stops_arg;

	for (auto st: stops_arg)
		stops[st].push_back(bus);
}

void BusesForStopsEx(map<string, vector<string>>& stops, string stop, string bus_ex)
{
	if (stops.count(stop) == 0)
		cout << "No stop" << endl;
	else
		WriteVectorEx(stops[stop], bus_ex);
}

void StopsForBus(map<string, vector<string>>& stops, map<string, vector<string>>& buses, string bus)
{
	if (buses.count(bus) == 0)
		cout << "No bus" << endl;
	else
	{
		for (auto stop: buses[bus])
		{
			cout << "Stop " << stop << ": ";
			BusesForStopsEx(stops, stop, bus);	
		}
	}
}

void AllBuses(map<string, vector<string>>& stops, map<string, vector<string>>& buses)
{
	if (buses.size() > 0)
	{
		for (auto bus: buses)
		{
			cout << "Bus " << bus.first << ": ";
			for (auto stop: bus.second)
				cout << stop << " ";
			cout << endl;
		}
	}
	else
		cout << "No buses" << endl;
}
			

int main()
{
	map<string, vector<string>> buses;
	map<string, vector<string>> stops;
	vector<string> stops_arg;


	int cmd_int;
	string cmd;
	int arg_int;
	string bus;
	string arg_string;

	int cmd_num;
	cin >> cmd_num;
	
	for (int i=0; i<cmd_num; i++)
	{
		cin >> cmd;
		cmd_int = ParseCMD(cmd);

		switch (cmd_int)
		{
			case NEW_BUS:
				cin >> bus;
				cin >> arg_int;
				stops_arg = ReadStops(arg_int);
				NewBus(stops, buses, bus, stops_arg);
			break;

			case BUSES_FOR_STOP:
				cin >> arg_string;
				BusesForStopsEx(stops, arg_string, "FUCK");
			break;
			
			case STOPS_FOR_BUS:
				cin >> arg_string;
				StopsForBus(stops, buses, arg_string);
			break;

			case ALL_BUSES:
				AllBuses(stops, buses);
			break;

			case ERROR:
				cout << "ERROR" << endl;
				return 0;

			break;
				
			default:
				cout << "ERROR" << endl;
				return 0;
			break;
		}
	}
	return 0;
}
