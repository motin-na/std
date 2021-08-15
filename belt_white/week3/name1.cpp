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

	private:	
		map<int , string> fname_hist;
		map<int , string> lname_hist;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}
