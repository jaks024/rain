// rain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <tests/TestGame.hpp>
#include <rain/events/EventArgs.hpp>
#include <rain/events/EventHandler.hpp>
#include <rain/config/ConfigDeSerializer.hpp>
#include <rain/rendering/RenderLayer.hpp>
#include <rain/rendering/RenderLayerManager.hpp>

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

void TestConfigDeSerializer(string folderPath) 
{
	string configPath = folderPath.append("config.cfg");
	string content = "tebsd fsdaf sd\nfewfaew fewfjl";
	//ConfigDeSerializer::Serialize(&configPath, &content);
	//vector<string> s = ConfigDeSerializer::Deserialize(&configPath);
	//for (auto& i : s)
	//{
	//	printf((i + "\n").c_str());
	//}

	unordered_map<SDL_Keycode, SDL_Keycode> keybinds;
	keybinds.insert({ SDLK_a, SDLK_b });
	keybinds.insert({ SDLK_c, SDLK_d });
	keybinds.insert({ SDLK_e, SDLK_e });
	keybinds.insert({ SDLK_AC_BACK, SDLK_AC_REFRESH });
	keybinds.insert({ SDLK_COLON, SDLK_COMMA});
	ConfigDeSerializer::SerializeInputConfig(&keybinds, &configPath);
	
	unordered_map<SDL_Keycode, SDL_Keycode> deserializedKeybinds;
	deserializedKeybinds = ConfigDeSerializer::DeserializeInputConfig(&configPath);
	for (auto& [key, val] : deserializedKeybinds)
	{
		std::cout << SDL_GetKeyName(key) << ": " << SDL_GetKeyName(val) << "\n";
	}
}

void TestRenderLayer() 
{
	RenderLayer layer = RenderLayer("layer1", 0, true);
	Renderable obj1 = { 3, 0, 0 };
	Renderable obj2 = { 2, 0, 1 };
	Renderable obj3 = { 1, 0, 2 };
	Renderable obj4 = { 0, 0, 3 };
	layer.Add(obj1);
	layer.Add(obj4);
	layer.Add(obj3);
	layer.Add(obj2);

	//for (auto& obj : layer.objInLayer)
	//{
	//	printf(("obj idx: " + std::to_string(obj.index)).c_str());
	//	printf((" id: " + std::to_string(obj.id) + "\n").c_str());
	//}
	//layer.Remove(2);
	//layer.Remove(1);
	//for (auto& obj : layer.objInLayer)
	//{
	//	printf(("obj idx: " + std::to_string(obj.index)).c_str());
	//	printf((" id: " + std::to_string(obj.id) + "\n").c_str());
	//}
	//layer.Remove(-1);

	RenderLayerManager manager;
	manager.Create(0, "layer1", true);
	manager.Create(1, "layer1", true);
	manager.Create(2, "layer1", true);
	manager.AddObjToLayer(0, obj4);
	manager.AddObjToLayer(0, obj2);
	manager.AddObjToLayer(0, obj1);
	manager.AddObjToLayer(0, obj3);
	manager.AddObjToLayer(2, obj4);
	manager.AddObjToLayer(2, obj2);
	manager.AddObjToLayer(2, obj1);
	manager.AddObjToLayer(2, obj3);
	for (auto& obj : manager.Get(0)->objInLayer)
	{
		printf(("obj idx: " + std::to_string(obj.index)).c_str());
		printf((" id: " + std::to_string(obj.id) + "\n").c_str());
	}
	for (auto& obj : manager.Get(2)->objInLayer)
	{
		printf(("obj idx: " + std::to_string(obj.index)).c_str());
		printf((" id: " + std::to_string(obj.id) + "\n").c_str());
	}

	manager.RemoveObjFromLayer(0, obj4.id);
	manager.RemoveObjFromLayer(0, obj3.id);
	manager.RemoveObjFromLayer(2, obj4.id);
	manager.RemoveObjFromLayer(2, obj3.id);

	for (auto& obj : manager.Get(0)->objInLayer)
	{
		printf(("obj idx: " + std::to_string(obj.index)).c_str());
		printf((" id: " + std::to_string(obj.id) + "\n").c_str());
	}
	for (auto& obj : manager.Get(2)->objInLayer)
	{
		printf(("obj idx: " + std::to_string(obj.index)).c_str());
		printf((" id: " + std::to_string(obj.id) + "\n").c_str());
	}

}

int main(int argc, char* argv[])
{
	TestRenderLayer();

	return 0;

	string exePath = string(argv[0]);
	string folderPath = exePath.substr(0, exePath.find_last_of("\\") + 1);
	printf((folderPath + "\n").c_str());
	TestConfigDeSerializer(folderPath);

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
