#include <log4cpp\Category.hh>
#include <log4cpp\PropertyConfigurator.hh>

using namespace std;

class MyLogger
{
public:
	MyLogger()
	{
	}
	virtual ~MyLogger()
	{
		log4cpp::Category::shutdown();
	}
	bool Init()
	{
		try
		{
			string initFileName = "log4cpp.property";
			log4cpp::PropertyConfigurator::configure(initFileName);
		}
		catch(log4cpp::ConfigureFailure& f)
		{
			std::cout << "Configure Problem" << f.what() << std::endl;
			return false;
		}
		return true;
	}
	void LogDebug(string message)
	{
		log4cpp::Category &mylogger = log4cpp::Category::getInstance("MyLogger");
		mylogger.debug(message);
	}
	void Loginfo(string message)
	{
		log4cpp::Category &mylogger = log4cpp::Category::getInstance("MyLogger");
		mylogger.info(message);
	}
};