
#include <boost/filesystem.hpp>
#include "easylogging++.h"

#define ELPP_NO_DEFAULT_LOG_FILE

_INITIALIZE_EASYLOGGINGPP

void rolloutHandler(const char* filename, std::size_t size)
{
	static unsigned int idx = 0;
	std::stringstream stream;
	stream << filename << "." << ++idx;
	boost::filesystem::rename(filename, stream.str().c_str());

}

int main(int argc, char** argv)
{
	el::Loggers::addFlag(el::LoggingFlag::StrictLogFileSizeCheck);
	el::Configurations conf("log.conf");
	//el::Loggers::reconfigureLogger("default", conf);
	el::Loggers::reconfigureAllLoggers(conf);
	el::Helpers::installPreRollOutCallback(rolloutHandler);

	for (int i = 0; i < 100; ++i)
	{
		LOG(INFO) << "Test==========================================================";

	}

	el::Helpers::uninstallPreRollOutCallback();
	return 0;
}
