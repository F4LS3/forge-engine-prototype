#pragma once

#include "core.h"

namespace Forge {
	class FORGE_API Application {
	public:
		Application();
		virtual ~Application();

		void run();
	};

	Application* create_application();
}