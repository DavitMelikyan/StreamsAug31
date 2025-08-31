#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

int main() {
    std::ifstream in("task6.txt");
    std::unordered_map<std::string, std::string> mp;
    std::string line;
    while (getline(in,line)) {
        std::stringstream ss (line);
        std::string key;
        getline(ss, key, '=');
        std::string value;
        ss >> value;
        mp[key] = value;
    }
    in.close();
    auto get = [&](const std::string& key) { 
        if(!mp.count(key)) throw std::runtime_error("Wrong key");
        return mp[key];
    };
    auto set = [&](const std::string& key, const std::string& value) {
        mp[key] = value;
        std::ofstream out("task6.txt");
        for (const auto& [key, value] : mp) {
            out << key << "=" << value << std::endl;
        }
        out.close();
    };
    auto del = [&](const std::string& key) {
        if(!mp.count(key)) throw std::runtime_error("Wrong key");
        mp.erase(key);
        std::ofstream out("task6.txt");
        for (const auto& [key, value] : mp) {
            out << key << "=" << value << std::endl;
        }
        out.close();
    };
    // std::cout << get("username") << std::endl;
    // set("username", "davit");
    // set("task", "6");
    // del("task");
}