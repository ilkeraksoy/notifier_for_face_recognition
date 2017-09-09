#include "Notifier.h"

Notifier::Notifier(vector<string> &personNames, const string serverName) : threads() {

	this->serverName = serverName;

	for (vector<string>::iterator name = personNames.begin(); name != personNames.end(); name++) {

		this->personNames.push_back(*name);
	}

	threads = new thread[personNames.size()];
	mutexes = new mutex[personNames.size()];
}

void Notifier::sendMessage(const string &message, const int &messageId) {

	threads[messageId] = std::thread(&Notifier::sendAsync, this, message, messageId);

	threads[messageId].detach();
}

void Notifier::sendAsync(const string &message, const int &messageId) {

	mutexes[messageId].lock();

	auto r = cpr::Post(cpr::Url{ serverName },
		cpr::Multipart{ { "Message", message } });

	cout << r.text << endl;

	this_thread::sleep_for(5s);

	mutexes[messageId].unlock();
}