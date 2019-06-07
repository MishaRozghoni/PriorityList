#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <list>
#include <limits>
using namespace std;

//Class for messages
class Messages
{

public:
	Messages(const char* pszM, int pr)
		: sMessage(pszM), ssPriority(pr) {}
	string sMessage;
	int ssPriority;
	Messages() = default;
};

bool operator<(const Messages& m1, const Messages& m2)
{
	return m1.ssPriority < m2.ssPriority;
}

bool operator==(const Messages& m1, const Messages& m2)
{
	return m1.ssPriority == m2.ssPriority && m1.sMessage == m2.sMessage;
}

//Displaying messages from list
void displayMessages(list<Messages>& messages)
{
	list<Messages>::iterator iter = messages.begin();

	while (iter != messages.end())
	{
		Messages& m = *iter;
		cout << m.ssPriority << " - " << m.sMessage << endl;
		iter++;
	}
}

//Finding minimum priority in list
int min_priority(list<Messages>& messages)
{
	list<Messages>::iterator iter = messages.begin();
	int min = numeric_limits<int>::max();

	while (iter != messages.end())
	{
		Messages& m = *iter;
		if (m.ssPriority < min && m.ssPriority > 0)
		{
			min = m.ssPriority;
		}
		iter++;
	}
	cout << "\nMin priority in list: " << min << endl;
	return min;
}

//Adding messages to list
void atemtToAddItem(list<Messages>& messages)
{
	char mes[100];
	int priority;

	cout << "\nPlease, enter your message: ";
	cin >> mes;
	cout << "Please, enter message pririty (were lowes priority is \'1\') : ";
	cin >> priority;
	messages.push_back(Messages(mes, priority));
}

//Removing message with lowest priority
void priority_pop(list<Messages>& messages)
{
	int prior = min_priority(messages);
	list<Messages>::iterator iter = messages.begin();
	Messages& m = *iter;

	while (iter != messages.end())
	{
		Messages& m = *iter;
		if (m.ssPriority == prior)
		{
			messages.remove(m);
			break;
		}
		iter++;
	}
}



int main(int nNumberofArgs, char* pszArgs[])
{
	list<Messages> messages;

	int size = 0;
	cout << "Please, enter queue size: ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		atemtToAddItem(messages);
	}

	cout << "\nPriority queue:" << endl;
	messages.sort();
	displayMessages(messages);

	while (true) {
		priority_pop(messages);
		atemtToAddItem(messages);

		cout << "\nPriority queue:" << endl;
		messages.sort();
		displayMessages(messages);
	}

	system("PAUSE");
	return 0;
}