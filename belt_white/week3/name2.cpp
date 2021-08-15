#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


class Person
{
	public:
		void ChangeFirstName(int year, const string& first_name) 
		{
			fname_hist[year] = first_name;
		}

		void ChangeLastName(int year, const string& last_name) 
		{
			lname_hist[year] = last_name;
		}

		string GetFullName(int year) 
		{
			pair<string, string> answ;
			
			for (const auto& i: fname_hist)
				if (i.first <= year)
					answ.first = i.second;

			for (const auto& j: lname_hist)
				if (j.first <= year)
					answ.second = j.second;

			bool fnull = (answ.first == "");
			bool lnull = (answ.second == "");

			if (fnull && lnull)
				return "Incognito";
			else if (fnull)
				return answ.second + " with unknown first name";
			else if (lnull)
				return answ.first + " with unknown last name";
			else
				return answ.first + " " + answ.second;
		}

		string GetFullNameWithHistory(int year) 
		{
			vector<string> name;
			vector<string> lastname;
			string answ_name = "";
			string answ_lastname = "";

			for (const auto& i: fname_hist)
				if (i.first <= year)
				{
//					cout << i.first << endl;
//					cout << i.second << endl;
					if (name.size() == 0)
						name.push_back(i.second);
					else if (name[name.size()-1] != i.second)
						name.push_back(i.second);
				}

			for (const auto& j: lname_hist)
				if (j.first <= year)
				{
					if (lastname.size() == 0)
						lastname.push_back(j.second);
					else if (lastname[lastname.size()-1] != j.second)
						lastname.push_back(j.second);
				}

//			cout << name.size() << endl;
			if (name.size() != 0)
			{
				answ_name = name[name.size()-1];
				if (name.size() > 1)
				{
					answ_name += " (";
					for (int iname = name.size()-2; iname>=0; iname--)
						if (iname != name.size()-2)
							answ_name += ", " + name[iname];
						else
							answ_name += name[iname];
					answ_name += ")";
				}
			}

			if (lastname.size() != 0)
			{
				answ_lastname = lastname[lastname.size()-1];
				if (lastname.size() > 1)
				{
					answ_lastname += " (";
					for (int ilastname = lastname.size()-2; ilastname>=0; ilastname--)
						if (ilastname != lastname.size()-2)
							answ_lastname += ", " + lastname[ilastname];
						else
							answ_lastname += lastname[ilastname];
							
					answ_lastname += ")";
				}
			}

			bool fnull = (answ_name == "");
			bool lnull = (answ_lastname == "");

			if (fnull && lnull)
				return "Incognito";
			else if (fnull)
				return answ_lastname + " with unknown first name";
			else if (lnull)
				return answ_name + " with unknown last name";
			else
				return answ_name + " " + answ_lastname;


		}

	private:	
		map<int , string> fname_hist;
		map<int , string> lname_hist;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}

