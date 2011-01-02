#include <fstream>
#include <string>

#include <stdio.h>
#include <errno.h>

#define TOO_FEW_ARGUMENTS_SPECIFIED 1
#define SUPPLIED_VALUE_WAS_ZERO 2
#define SUPPLIED_VALUE_EXCEEDED_RANGE 4
#define SUPPLIED_VALUE_WAS_INVALID 8
#define COULD_NOT_OPEN_FILE 16

int main (int argc, char* argv[])
	{
	if(argc == 1)
		{
		exit(TOO_FEW_ARGUMENTS_SPECIFIED);
		}

	std::ifstream integerFile(argv[1]);
	unsigned long long targetValue = 0;
	
	if(integerFile.is_open())
		{
		std::string integerString;
		std::getline(integerFile, integerString);
		const char* cstr = integerString.c_str();
		
		if(!(targetValue = strtoull(cstr, (char**)NULL, 10)) && errno != ERANGE && errno != EINVAL)
			{
			exit(SUPPLIED_VALUE_WAS_ZERO);
			}
		else if(errno == ERANGE)
			{
			exit(SUPPLIED_VALUE_EXCEEDED_RANGE);
			}
		else if(errno == EINVAL)
			{
			exit(SUPPLIED_VALUE_WAS_INVALID);
			}
		}
	else
		{
		exit(COULD_NOT_OPEN_FILE);
		}

	for(unsigned long long i = 1; i <= targetValue; ++i)
		{
		if(!(i % 3) && !(i % 5))
			{
			printf("Hop\n");
			}
		else if(!(i % 5))
			{
			printf("Hophop\n");
			}
		else if(!(i % 3))
			{
			printf("Hoppity\n");
			}
		}
	return 0;
	}
