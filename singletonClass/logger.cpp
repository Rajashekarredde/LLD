#include "logger.hpp"

int logger::count = 0;
logger* logger ::loggerInstance = nullptr;
mutex logger::mtx;
