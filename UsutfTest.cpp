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

USUTF_TEST(testFoo)
{
	Usutf::test(foo(3) == 4);
	Usutf::test(foo(7) == 8);
}

USUTF_TEST(testBar)
{
	Usutf::test(bar(7) == 14);
}

int main(int argc, char *argv[])
{
	int exitCode = Usutf::runTests(argc, argv);
	return exitCode;
}
