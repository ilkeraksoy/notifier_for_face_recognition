#include <iostream>
#include <fstream>
#include <sstream>
#include <locale.h>

#include "Notifier.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "Turkish");

	vector<string> personNames;

	personNames.push_back("ilker");
	personNames.push_back("osman");

	Notifier notify(personNames);

	notify.sendMessage("hi i am osman", 1);
	notify.sendMessage("hi i am ilker", 0);

	system("PAUSE");
}