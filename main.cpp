#include <iostream>
#include <fstream>
#include <sstream>
#include <locale.h>
#include <cpr/cpr.h>


using namespace std;

void readJsonFile(string &body) {

	string temp;

	fstream read("json.txt");

	while (!read.eof())
	{
		getline(read, temp);
		body.append(temp);
	}
}

void sendNotification() {

	string body;

	readJsonFile(body);

	auto r = cpr::Post(cpr::Url{ "https://fcm.googleapis.com/fcm/send" },
		cpr::Body{ body },
		cpr::Header{ { "Content-Type", "application/json" },
		{ "Authorization","key=SERVER_API_KEY" } });

	std::cout << r.text << std::endl;
}

int main() {

	setlocale(LC_ALL, "Turkish");

	sendNotification();


	system("PAUSE");
}