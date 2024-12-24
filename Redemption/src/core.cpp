#include "core.h"

namespace Redemption
{
	// Found at https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
	std::vector<std::string> split(std::string string, char delimiter) {
		std::vector<std::string> result;
		std::stringstream ss(string);
		std::string item;

		while (getline(ss, item, delimiter)) {
			result.push_back(item);
		}

		return result;
	}
}