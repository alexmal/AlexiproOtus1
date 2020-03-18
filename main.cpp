#include <iostream>
#include "lib.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_sinks.h>

int main() {
    auto logger = spdlog::stdout_logger_mt("console");
//    std::cout << "Hello, World!" << std::endl;
    logger->info("version {} was started!", version());
//    logger->error("Hello world!");
    return 0;
}
