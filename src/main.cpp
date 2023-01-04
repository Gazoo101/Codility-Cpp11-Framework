// Std. Library
#include <iostream>
#include <memory>

// 3rd Party

// 1st Party (This application)
#include "TestHelper.h"

#include "Tasks/TaskExample.h"
#include "Tasks/TaskTemplate.h"

int main()
{
	// Compile set of tasks to execute
	std::vector<std::unique_ptr<TaskBase>> tasks;

	tasks.push_back( std::make_unique<TaskExample>() );
	tasks.push_back( std::make_unique<TaskTemplate>() );


	for (auto const& task : tasks)
	{
		task->RunTest();
	}
}