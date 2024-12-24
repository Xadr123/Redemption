#include "core.h"

namespace Redemption
{
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