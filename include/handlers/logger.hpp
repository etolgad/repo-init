#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <memory>
#include <mutex>

#include <spdlog/spdlog.h>

namespace handler
{
class Logger
{
    Logger();
    Logger(const Logger &) = delete;
    Logger(const Logger &&) = delete;
    Logger &operator=(const Logger &) = delete;
    Logger &operator=(const Logger &&) = delete;

    static std::unique_ptr<Logger> loggerIns;
    static std::mutex mutex;

    std::shared_ptr<spdlog::logger> logger_;

  public:
    ~Logger();

    static Logger &getLoggerInstance();
};
} // namespace handler

#endif // _LOGGER_H_