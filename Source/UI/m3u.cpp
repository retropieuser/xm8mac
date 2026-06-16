#include "m3u.h"

#include <fstream>
#include <string>
#include <filesystem>

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

} // namespace

M3UResult LoadM3U(const std::string& path)
{
    M3UResult result;
    result.success = false;

    std::ifstream file(path);
    if (!file.is_open()) {
        result.error = "unable to open m3u: " + path;
        return result;
    }

    // Base directory of the M3U file
    std::filesystem::path baseDir =
        std::filesystem::path(path).parent_path();

    std::string line;
    while (std::getline(file, line)) {
        line = Trim(line);

        if (line.empty()) {
            continue;
        }

        if (line[0] == '#') {
            continue;
        }

        // Resolve relative paths against M3U location
        std::filesystem::path resolved = baseDir / line;

        result.entries.push_back(resolved.lexically_normal().string());
    }

    result.success = true;
    return result;
}
