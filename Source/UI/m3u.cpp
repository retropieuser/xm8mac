#include "m3u.h"

#include <fstream>
#include <string>

namespace {

std::string Trim(const std::string& value)
{
    const auto first = value.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) {
        return "";
    }

    const auto last = value.find_last_not_of(" \t\r\n");
    return value.substr(first, last - first + 1);
}

}

M3UResult LoadM3U(const std::string& path)
{
    M3UResult result;
    result.success = false;

    std::ifstream file(path);
    if (!file.is_open()) {
        result.error = "unable to open m3u: " + path;
        return result;
    }

    std::string line;
    while (std::getline(file, line)) {
        line = Trim(line);

        if (line.empty()) {
            continue;
        }

        if (line[0] == '#') {
            continue;
        }

        result.entries.push_back(line);
    }

    result.success = true;
    return result;
}
