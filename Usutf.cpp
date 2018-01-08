#include <Usutf.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace Usutf;

int failCount = 0;
int passCount = 0;
int internalTestCount = 0;

static std::string toString(int x)
{
	std::ostringstream ss;
	ss << x;
	return ss.str();
}

Initializer *Initializer::tests = 0;

Initializer::Initializer(TestType x, const std::string &name)
{
	test = x;
	nextTest = tests;
	tests = this;
	testName = name;
}

Initializer *Initializer::getTests()
{
	return tests;
}

void Usutf::test(bool result)
{
	test(result, "");
}

void Usutf::test(bool result, const std::string &msg)
{
	if (result)
	{
		passCount++;
	}
	else
	{
		std::cout << "> FAILED: (" + toString(internalTestCount) + ") " + msg + "\n";
		failCount++;
	}
	internalTestCount++;
}

int Usutf::runTests(int argc, char *argv[])
{
	Usutf::Initializer *p = Usutf::Initializer::getTests();
	std::vector<Usutf::Initializer *> tests;
	for (;;)
	{
		if (!p)
			break;
		tests.push_back(p);
		p = p->getNextTest();
	}

	int n = (int)tests.size();
	for (int i = 0; i < n; i++)
	{
		p = tests[n - i - 1];
		int oldFailCount = failCount;
		TestType test = p->getTest();
		std::cout << "Running test " + p->getTestName() << "...\n";
		std::cout.flush();
		internalTestCount = 0;
		test();
		if (failCount == oldFailCount)
		{
			std::cout << "PASSED\n";
			std::cout.flush();
		}
		else
		{
			std::cout << "FAILED\n";
			std::cout.flush();
		}
	}

	std::cout << "Total fail count is " << failCount << ".\n";

	return getExitCode();
}

int Usutf::getExitCode()
{
	if (failCount == 0)
		return 0;

	return 1;
}
