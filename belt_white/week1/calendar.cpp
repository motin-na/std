#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

#define ERROR -1
#define ADD 0
#define DUMP 1
#define NEXT 2

int ParseCMD(string cmd)
{
	if (cmd == "ADD")
		return ADD;
	else if (cmd == "DUMP")
		return DUMP;
	else if (cmd == "NEXT")
		return NEXT;

	return ERROR;
}

int NextMonth(int month)
{
	if (month == 11)
		return 0;
	else
		return ++month;
}

void TaskMigration(vector<vector<string>>& s, int days)
{
	int last_day = s.size()-1+days;
	for (int i=s.size()-1; i > s.size()-1+days; i--)
		s[last_day].insert(end(s[last_day]), begin(s[i]), end(s[i]));	
}

int SwitchMonth(vector<vector<string>>& s, int month)
{
	const int days_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int days = days_month[NextMonth(month)] - days_month[month];

	if (days > 0)
		s.resize(s.size() + days);
	else if (days < 0)
	{
		TaskMigration(s, days);
		s.resize(s.size() + days);
	}

	return NextMonth(month);
}

void AddTask(vector<vector<string>>& s, int i, string str_add)
{
	s[i].push_back(str_add);
}

void DumpTasks(const vector<vector<string>>& s, int day)
{
	cout << s[day].size() << " ";

	for (auto i: s[day])
		cout << i << " ";

	cout << endl;
}
		
			

int main()
{
	int month = 0;
	vector<vector<string>> s(31);

	int cmd_int;
	string cmd;
	int arg_int;
	string arg_string;

	int cmd_num;
	cin >> cmd_num;
	
	for (int i=0; i<cmd_num; i++)
	{
		cin >> cmd;
		cmd_int = ParseCMD(cmd);

		switch (cmd_int)
		{
			case ADD:
				cin >> arg_int;
				cin >> arg_string;
				AddTask(s, arg_int-1, arg_string);
			break;

			case DUMP:
				cin >> arg_int;
				DumpTasks(s, arg_int-1);
			break;
			
			case NEXT:
				month = SwitchMonth(s, month);
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
