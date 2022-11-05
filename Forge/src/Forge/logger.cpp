#include "logger.h"

namespace Forge {
    std::shared_ptr<spdlog::logger> Logger::forge_logger;
    std::shared_ptr<spdlog::logger> Logger::client_logger;

    void Logger::init() {
        spdlog::set_pattern("[%D %T] [%l] [%n | %t] -> %v");

        forge_logger = spdlog::stdout_color_mt("FORGE");
        forge_logger->set_level(spdlog::level::trace);

        client_logger = spdlog::stdout_color_mt("CLIENT");
        client_logger->set_level(spdlog::level::trace);
    }
}