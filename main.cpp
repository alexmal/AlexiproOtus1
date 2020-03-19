#include <iostream>
#include "lib.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_sinks.h>

int main() {
    auto logger = spdlog::stdout_logger_mt("console");
    logger->info("version {} was started!", version());
    return 0;
}
