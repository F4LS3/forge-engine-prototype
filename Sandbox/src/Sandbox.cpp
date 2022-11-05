#include <forge.h>

class Sandbox : public Forge::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

Forge::Application* Forge::create_application() {
	return new Sandbox();
}