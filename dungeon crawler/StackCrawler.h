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
		std::cout<<szText;
		StackWalker::OnOutput(szText); 
  }
};