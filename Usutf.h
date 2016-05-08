#ifndef __SUTF_H
#define __SUTF_H

#include <string>
#include <iostream>

#define USUTF_REGISTER_TEST(x) \
void x()

#define USUTF_EXPECT_TRUE(x) Usutf::test(x)

#define USUTF_RUN_TEST(x) \
{ \
	void x(); \
	int oldFailCount = Usutf::failCount; \
	std::cout << "Running test " << #x << "\n"; \
	Usutf::internalTestCount = 0; \
	x(); \
	if (oldFailCount == Usutf::failCount) \
		std::cout << "PASSED\n"; \
	else \
		std::cout << "FAILED\n"; \
}

class Usutf
{
public:
	static void test(bool result);
	static void printRapport();
	static int getExitCode();
	static int failCount;
	static int passCount;
	static int internalTestCount;
};

#endif

