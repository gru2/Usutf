#include <Usutf.h>

using namespace std;

int foo(int x)
{
	return x + 1;
}

int bar(int x)
{
	return x + x;
}

USUTF_REGISTER_TEST(testFoo)
{
	USUTF_EXPECT_TRUE(foo(4) == 5);
}

USUTF_REGISTER_TEST(testBar)
{
	USUTF_EXPECT_TRUE(bar(4) == 8);
	USUTF_EXPECT_TRUE(bar(7) == 13);
	USUTF_EXPECT_TRUE(bar(0) == 0);
	USUTF_EXPECT_TRUE(bar(5) == 11);
}

int main(int argc, char *argv[])
{
	USUTF_RUN_TEST(testFoo);
	USUTF_RUN_TEST(testBar);
	return Usutf::getExitCode();
}
