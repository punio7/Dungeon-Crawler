#pragma once
#include <iostream>
#include "StackWalker\StackWalker.h"

class StackCrawler : public StackWalker
{
public:
  StackCrawler() : StackWalker() {}
protected:
  virtual void OnOutput(LPCSTR szText)
    { 
		std::wcout<<szText;
		StackWalker::OnOutput(szText); 
  }
};