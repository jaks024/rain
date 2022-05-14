#pragma once
#include <string>
using std::string;
struct EventArgs
{
	string message;

	EventArgs(void) = default;
	EventArgs(string message) : message{ message } {}
	virtual ~EventArgs(void) = default;
};

