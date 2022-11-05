#pragma once

#include "application.h"
#include "logger.h"

#ifdef FORGE_PLATFORM_WINDOWS
extern Forge::Application* Forge::create_application();

int main(int argc, char** argv) {
	Forge::Logger::init();

	FORGE_CORE_INFO("Forge logger initialised");
	FORGE_INFO("Client logger initialised");

	auto app = Forge::create_application();
	app->run();
	delete app;
}
#endif