#ifndef __USUTF_H
#define __USUTF_H

#include <string>

#define USUTF_TEST(x) \
void x(); \
static Usutf::Initializer initializer##x(x, #x); \
void x()

namespace Usutf
{

typedef void (*TestType)();

class Initializer
{
public:
	Initializer(TestType x, const std::string &name);

	static Initializer *getTests();
	static void setLastTest(const std::string &name);
	static Initializer **findTest(const std::string &name);

	TestType getTest() const { return test; }
	void setTest(TestType x) { test = x; }
	Initializer *getNextTest() const { return nextTest; }
	std::string &getTestName() { return testName; }
protected:
	static Initializer *tests;
	Initializer *nextTest;
	TestType test;
	std::string testName;
};

void test(bool result);
void test(bool result, const std::string &msg);

int runTests(int argc, char *argv[]);
int getExitCode();
}

#endif
