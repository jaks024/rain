#pragma once
#include <vector>
#include <functional>
#include <memory>
using std::vector;
using std::function;
using std::shared_ptr;
#include <rain/events/EventArgs.hpp>

template<class T>
class EventHandler
{
private:
	vector<function<void(T)>> subscribedFunctions;

public:
	void Invoke(T arg)
	{
		for (auto& func : subscribedFunctions)
		{
			func(arg);
		}
	}

	EventHandler<T>* operator+=(const function<void(T)> e)
	{
		subscribedFunctions.push_back(e);
		return this;
	}

	EventHandler<T>* operator-=(const function<void(T)> e)
	{
		for (auto it = subscribedFunctions.begin(); it != subscribedFunctions.end(); ++it)
		{
			if ((*it).target<function<void(T)>>() == e.target<function<void(T)>>()) {
				subscribedFunctions.erase(it);
				break;
			}
		}
		return this;
	}
};
