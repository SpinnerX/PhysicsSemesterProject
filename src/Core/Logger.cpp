#include <Core/Logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace PhysicsSimulation{
    Ref<spdlog::logger> Logger::coreLogger;
    Ref<spdlog::logger> Logger::clientLogger;

    void Logger::Init(){
        spdlog::set_pattern( "%^[%n - %T] ------- %v%$");
        coreLogger = spdlog::stdout_color_mt("Simulator");
        coreLogger->set_level(spdlog::level::trace);

        clientLogger = spdlog::stdout_color_mt("Application");
        clientLogger->set_level(spdlog::level::trace);
    }

};
