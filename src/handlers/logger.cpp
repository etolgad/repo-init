#include <spdlog/sinks/dup_filter_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/syslog_sink.h>

#include "handlers/logger.hpp"

std::unique_ptr<handler::Logger> handler::Logger::loggerIns(nullptr);
std::mutex handler::Logger::mutex;

handler::Logger::Logger()
{
}

handler::Logger &handler::Logger::getLoggerInstance()
{
    std::lock_guard<std::mutex> lg(mutex);
    if (!loggerIns)
    {
        loggerIns.reset(new Logger());
    }

    return *loggerIns;
}

handler::Logger::~Logger()
{
    // this->logger_->flush();
}
