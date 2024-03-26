#include <Core/EntryPoint.h>
#include <Core/Application.h>
#include <Core/Logger.h>
using namespace PhysicsSimulation;

extern PhysicsSimulation::Application* PhysicsSimulation::CreateApplication();

int main(int argc, char** argv){
	Logger::Init();
	auto app = CreateApplication();
	app->run();

	delete app;
	return 0;
}
