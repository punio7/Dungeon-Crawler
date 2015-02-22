//#include "Log4CppLogger.h"
//#include <log4cpp\Category.hh>
//#include <log4cpp\PropertyConfigurator.hh>
//#include <log4cpp\RollingFileAppender.hh>
//#include <log4cpp\PatternLayout.hh>
//
//using namespace std;
//
//Log4CppLogger::Log4CppLogger()
//{
//
//}
//
//Log4CppLogger::~Log4CppLogger()
//{
//	log4cpp::Category::shutdown();
//}
//
//bool Log4CppLogger::Init(string initFileName)
//{
//	try
//	{
//		log4cpp::PropertyConfigurator::configure(initFileName);
//	}
//	catch(log4cpp::ConfigureFailure& f)
//	{
//		std::cout << "Configure Problem" << f.what() << std::endl;
//		return false;
//	}
//	return true;
//}
//
//void Log4CppLogger::LogDebug(string message)
//{
//	//log4cpp::Category &mylogger = log4cpp::Category::getInstance("sub1");
//	//mylogger.debug(message);
//
//	log4cpp::Category& sub1 = 
//		log4cpp::Category::getInstance(std::string("sub1"));
//
//	log4cpp::Category& sub2 = 
//		log4cpp::Category::getInstance(std::string("sub1.sub2"));
//
//	log4cpp::Category& root = log4cpp::Category::getRoot();
//
//	//root.warn("Storm is coming");
//
//	//sub1.debug("Received storm warning");
//	//sub1.info("Closing all hatches");
//
//	//sub2.debug("Hiding solar panels");
//	//sub2.error("Solar panels are blocked");
//	//sub2.debug("Applying protective shield");
//	//sub2.warn("Unfolding protective shield");
//	//sub2.info("Solar panels are shielded");
//
//	//sub1.info("All hatches closed");
//
//	//root.info("Ready for storm.");
//}
//
//void Log4CppLogger::LogInfo(string message)
//{
//	log4cpp::Category &mylogger = log4cpp::Category::getInstance("sub1");
//	mylogger.info(message);
//}