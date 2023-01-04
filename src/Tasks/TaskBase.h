#pragma once

#include "TestHelper.h"

class TaskBase {
public:

	virtual ~TaskBase() = default;
	
	virtual void RunTest() = 0;

protected:

	TestHelper mTestHelper;

};