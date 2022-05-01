#pragma once
#include <string>
using std::string;
struct EventArgs
{
	string message;

	EventArgs(void) = default;
	virtual ~EventArgs(void) = default;
};

