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

	 {"А", 1}, {"В", 1} , {"Е", 1}, {"И", 1}, {"Н", 1}, {"О", 1}, {"Р", 1}, {"С", 1}, {"Т", 1},
	 {"Д", 2}, {"К", 2} , {"Л", 2}, {"М",2 }, {"П", 2}, {"У", 2},
	 {"Б", 3}, {"Г", 3} , {"Ё", 3}, {"Ь", 3}, {"Я", 3},
	 {"Й", 4}, {"Ы", 4},
	 {"Ж", 5}, {"З", 5} , {"Х", 5}, {"Ц", 5}, {"Ч", 5},
	 {"Ш", 8}, {"Э", 8} , {"Ю", 8},
	 {"Ф", 10}, {"Щ", 10} , {"Ъ", 10}
	};
	string userWord;
	int points;
	while (true) {
		points = 0;
		cout << "Введите слово CAPSLock или 0 для выхода: ";
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
		cout << "Слово: \"" << userWord << "\" стоимость: " << points << "\n";
	}

	return 0;
}