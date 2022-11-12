#include "application.h"

namespace Forge {
	Application::Application() = default;
	Application::~Application() = default;

	void Application::run() {
        /*EventPublisher::subscribe(new Events::WindowResizedSubscriber());
        EventPublisher::queue_event(new Events::WindowResizedEvent(1280, 720));

        FORGE_CORE_TRACE("Event queued and subbed");
        EventPublisher::dispatch_queue();*/

		while (true);
	}
}