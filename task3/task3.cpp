#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

int main() {
    std::ifstream in ("task3.ini");
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> mp;
    std::string line;
    while (getline(in, line)) {
        std::stringstream ss(line);
        std::string section;
        getline(ss, section, '[');
        getline(ss, section, ']');
        while (getline(in, line)) {
            if (line.size() == 0) break;
            std::stringstream ss(line);
            std::string key;
            std::string value;
            ss >> key;
            getline(ss, value, '=');
            ss >> value;
            mp[section][key] = value;
        }
    }
    auto get = [&](const std::string& section, const std::string& key) {
        if (!mp.count(section) || !mp[section].count(key)) throw std::runtime_error("Wrong section or key");
        return mp[section][key];
    };
    std::cout << get("Database", "host") << std::endl;
    std::cout << get("Database","port") << std::endl;
    std::cout << get("Logging","level") << std::endl;
    in.close();
}
