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
//bool Log4CppLogger::Init(wstring initFileName)
//{
//	try
//	{
//		log4cpp::PropertyConfigurator::configure(initFileName);
//	}
//	catch(log4cpp::ConfigureFailure& f)
//	{
//		std::wcout << "Configure Problem" << f.what() << std::endl;
//		return false;
//	}
//	return true;
//}
//
//void Log4CppLogger::LogDebug(wstring message)
//{
//	//log4cpp::Category &mylogger = log4cpp::Category::getInstance(L"sub1");
//	//mylogger.debug(message);
//
//	log4cpp::Category& sub1 = 
//		log4cpp::Category::getInstance(std::wstring(L"sub1"));
//
//	log4cpp::Category& sub2 = 
//		log4cpp::Category::getInstance(std::wstring(L"sub1.sub2"));
//
//	log4cpp::Category& root = log4cpp::Category::getRoot();
//
//	//root.warn(L"Storm is coming");
//
//	//sub1.debug(L"Received storm warning");
//	//sub1.info(L"Closing all hatches");
//
//	//sub2.debug(L"Hiding solar panels");
//	//sub2.error(L"Solar panels are blocked");
//	//sub2.debug(L"Applying protective shield");
//	//sub2.warn(L"Unfolding protective shield");
//	//sub2.info(L"Solar panels are shielded");
//
//	//sub1.info(L"All hatches closed");
//
//	//root.info(L"Ready for storm.");
//}
//
//void Log4CppLogger::LogInfo(wstring message)
//{
//	log4cpp::Category &mylogger = log4cpp::Category::getInstance(L"sub1");
//	mylogger.info(message);
//}