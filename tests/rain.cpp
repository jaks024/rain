// rain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <tests/TestGame.hpp>
#include <rain/events/EventArgs.hpp>
#include <rain/events/EventHandler.hpp>

class TestFuncClass
{
public:
	void TestFunc1(EventArgs args) {
		printf(("1 called test func: " + args.message).c_str());
	}
	void TestFunc2(EventArgs args) {
		printf(("2 called test func: " + args.message).c_str());
	}
};

class TestEventClass {
public:

	TestFuncClass tfc;
	void Subscribe1(EventHandler<EventArgs>* myEvent) {
		(*myEvent) += std::bind(&TestFuncClass::TestFunc1, tfc, std::placeholders::_1);;
	}
	void Subscribe2(EventHandler<EventArgs>* myEvent) {
		(*myEvent) += std::bind(&TestFuncClass::TestFunc2, tfc, std::placeholders::_1);
	}

	void UnSubcribe1(EventHandler<EventArgs>* myEvent) {
		(*myEvent) -= std::bind(&TestFuncClass::TestFunc1, tfc, std::placeholders::_1);
	}
	void UnSubcribe2(EventHandler<EventArgs>* myEvent) {
		(*myEvent) -= std::bind(&TestFuncClass::TestFunc2, tfc, std::placeholders::_1);
	}
};


void TestEvent() {
	EventHandler<EventArgs> myEvent;
	EventArgs arg = EventArgs();

	TestEventClass tec1;
	tec1.Subscribe1(&myEvent);
	TestEventClass tec2;
	tec2.Subscribe2(&myEvent);

	arg.message = "3\n";
	myEvent.Invoke(arg);

	tec1.UnSubcribe1(&myEvent);

	arg.message = "4\n";
	myEvent.Invoke(arg);

	tec2.UnSubcribe2(&myEvent);

	arg.message = "5\n";
	myEvent.Invoke(arg);

	tec1.Subscribe1(&myEvent);

	arg.message = "6\n";
	myEvent.Invoke(arg);

	tec1.Subscribe2(&myEvent);

	arg.message = "7\n";
	myEvent.Invoke(arg);
}

void TestConfigDeSerializer(void) {


}

int main(int argc, char* args[])
{
	TestEvent();
	return 0;


	TestGame* testGame = new TestGame("test game", 60, 1280, 720);
	testGame->Start();
	while (!testGame->hasQuit) {
		testGame->Play();
	}
	testGame->Close();

	delete(testGame);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
