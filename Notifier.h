#ifndef NOTIFIER_H
#define NOTIFIER_H

#include <iostream>
#include <string>
#include <thread>
#include <mutex>

#include "cpr/cpr.h"

using namespace std;

class Notifier {

private:

	thread *threads;
	mutex *mutexes;

	vector<string> personNames;
	string serverName;

public:

	Notifier(vector<string> &personNames, const string serverName = "localhost/sendNotification.php");
	void sendMessage(const string &message, const int &messageId);
	void sendAsync(const string &message, const int &messageId);
};

#endif //NOTIFIER_H