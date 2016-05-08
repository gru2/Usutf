#include <Usutf.h>
#include <iostream>
#include <stdlib.h>

int Usutf::failCount = 0;
int Usutf::passCount = 0;
int Usutf::internalTestCount = 0;

void Usutf::test(bool result)
{
	if (result)
	{
		passCount++;
	}
	else
	{
		std::cout << "FAILED (" << internalTestCount << ") \n";
		failCount++;
	}
	internalTestCount++;
}

void Usutf::printRapport()
{
	std::cout << "Total pass count is " << passCount << ".\n";
	std::cout << "Total fail count is " << failCount << ".\n";
}

int Usutf::getExitCode()
{
	if (failCount == 0)
		return 0;

	return 1;
}
