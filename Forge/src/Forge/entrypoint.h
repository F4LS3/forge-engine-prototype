#pragma once

#include "application.h"

#ifdef FORGE_PLATFORM_WINDOWS
extern Forge::Application* Forge::create_application();

int main(int argc, char** argv) {
	auto app = Forge::create_application();
	app->run();
	delete app;
}
#endif