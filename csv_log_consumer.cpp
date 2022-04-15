#include "csv_log_consumer.h"


csv_log_consumer::csv_log_consumer(std::string fileName) : csvFile_(fileName)
{
	if (!csvFile_.is_open()) {
		throw std::logic_error("can not open file");
	}
}

void csv_log_consumer::logMessage(structures::LogType type, const std::string& message)
{
	csvFile_ << logTypeToString(type) << ";" << message << std::endl;
}

void csv_log_consumer::logDuration(size_t size, tests::DurationTime duration, const std::string& message)
{
	csvFile_ << size << ";" << duration.count() << ";" << message << std::endl;
}

void csv_log_consumer::zapisDoRiadku(tests::DurationTime duration)
{
	csvFile_ << duration.count() << ";";
}

void csv_log_consumer::odriadkuj()
{
	csvFile_ << std::endl;
}
