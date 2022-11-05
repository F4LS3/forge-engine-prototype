#pragma once

#include <memory>

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Forge {
	class FORGE_API Logger
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& get_forge_logger() { return forge_logger; }
		inline static std::shared_ptr<spdlog::logger>& get_client_logger() { return client_logger; }

	private:
		static std::shared_ptr<spdlog::logger> forge_logger;
		static std::shared_ptr<spdlog::logger> client_logger;
	};
}

#ifndef FORGE_DISTREBUTION
#define FORGE_CORE_FATAL(...) ::Forge::Logger::get_forge_logger()->fatal(__VA_ARGS__)
#define FORGE_CORE_ERROR(...) ::Forge::Logger::get_forge_logger()->error(__VA_ARGS__)
#define FORGE_CORE_WARN(...)  ::Forge::Logger::get_forge_logger()->warn(__VA_ARGS__)
#ifndef FORGE_RELEASE
#define FORGE_CORE_INFO(...)  ::Forge::Logger::get_forge_logger()->info(__VA_ARGS__)
#define FORGE_CORE_TRACE(...) ::Forge::Logger::get_forge_logger()->trace(__VA_ARGS__)
#else
#define FORGE_CORE_INFO
#define FORGE_CORE_TRACE
#endif
#else
#define FORGE_CORE_FATAL
#define FORGE_CORE_ERROR
#define FORGE_CORE_WARN
#define FORGE_CORE_INFO
#define FORGE_CORE_TRACE
#endif

#define FORGE_FATAL(...) ::Forge::Logger::get_forge_logger()->fatal(__VA_ARGS__)
#define FORGE_ERROR(...) ::Forge::Logger::get_forge_logger()->error(__VA_ARGS__)
#define FORGE_WARN(...)  ::Forge::Logger::get_forge_logger()->warn(__VA_ARGS__)
#define FORGE_INFO(...)  ::Forge::Logger::get_forge_logger()->info(__VA_ARGS__)
#define FORGE_TRACE(...) ::Forge::Logger::get_forge_logger()->trace(__VA_ARGS__)