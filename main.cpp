#include <list>
#include <set>
#include <vector>
#include <iostream>
#include <map>

#include <Windows.h>
#include <cstring>


using namespace std;
int getMatchCount(string where, string what) {
	int count = 0;
	string::size_type whatIndex = where.find(what);
	while (whatIndex != std::string::npos) {
		++count;
		whatIndex = where.find(what, whatIndex + what.length());
	}
	return count;
}

int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	

	map<string, int> letterPoints = {
	 {"A", 1}, {"E", 1}, {"I", 1}, {"O", 1}, {"U", 1}, {"L", 1}, {"N", 1}, {"S", 1}, {"T", 1}, {"R", 1},
	 {"D", 2}, {"G", 2},
	 {"B", 3}, {"C", 3}, {"M", 3}, {"P", 3},
	 {"F", 4}, {"H", 4}, {"V", 4}, {"W", 4}, {"Y", 4},
	 {"K", 5},
	 {"J", 8}, {"X", 8},
	 {"Q", 10}, {"Z", 10},

	 {"�", 1}, {"�", 1} , {"�", 1}, {"�", 1}, {"�", 1}, {"�", 1}, {"�", 1}, {"�", 1}, {"�", 1},
	 {"�", 2}, {"�", 2} , {"�", 2}, {"�",2 }, {"�", 2}, {"�", 2},
	 {"�", 3}, {"�", 3} , {"�", 3}, {"�", 3}, {"�", 3},
	 {"�", 4}, {"�", 4},
	 {"�", 5}, {"�", 5} , {"�", 5}, {"�", 5}, {"�", 5},
	 {"�", 8}, {"�", 8} , {"�", 8},
	 {"�", 10}, {"�", 10} , {"�", 10}
	};
	string userWord;
	int points;
	while (true) {
		points = 0;
		cout << "������� ����� CAPSLock ��� 0 ��� ������: ";
		cin >> userWord;
		if (userWord == "0") {
			break;
		}

		for (auto scrString : letterPoints) {
			int count = getMatchCount(userWord, scrString.first);
			if (!count) {
				continue;
			}
			points += scrString.second * count;
		}
		cout << "�����: \"" << userWord << "\" ���������: " << points << "\n";
	}

	return 0;
}