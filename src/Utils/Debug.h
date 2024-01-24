#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"

// Debug Macro
#define DEBUG

#define LOG_INFO(message) Logger::LogInfo(#message)
#define LOG_WARN(message)  Logger::LogWarn(#message)
#define LOG_ERROR(message) Logger::LogError(#message)

class Logger
{
public:
    static void init() {
        Logger();
    }

    static void LogInfo(const char* message) {
        if (m_Logger.get() == nullptr)
            spdlog::error("{}!", "Initialize Logger. Logger::init()");
        else
            m_Logger->info("{}!", message);
    }

    static void LogWarn(const char* message) {
        if (m_Logger.get() == nullptr)
            spdlog::error("{}!", "Initialize Logger. Logger::init()");
        else
            m_Logger->warn("{}!", message);
    }

    static void LogError(const char* message) {
        if (m_Logger.get() == nullptr)
            spdlog::error("{}!", "Initialize Logger. Logger::init()");
        else
            m_Logger->error("{}!", message);
    }

private:
    inline static std::shared_ptr<spdlog::logger> m_Logger{ nullptr };
    Logger()
    {
        this->m_Logger = spdlog::stdout_color_mt("console");
        m_Logger->set_pattern("%^[%T] %n: %v%$");
    }
    ~Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};