#pragma once

#include "Logger.hpp"

#include <iostream>

class ConsoleLogger : public Logger {
public:
    void log(const std::string& msg) override {
        std::cout << msg << std::endl;
    }
};

