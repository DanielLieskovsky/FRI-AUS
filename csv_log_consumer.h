#pragma once

#include "./structures/_logger/logger.h"
#include "tests/test.h"
#include <fstream>

class csv_log_consumer : public structures::ILogConsumer
{
public:
	csv_log_consumer(std::string fileName);

	void logMessage(structures::LogType type, const std::string& message) override;
	void logDuration(size_t size, tests::DurationTime duration, const std::string& message) override;
	void zapisDoRiadku(tests::DurationTime duration);
	void odriadkuj();
private:
	std::ofstream csvFile_;
};

