#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <map>

int main(int argc, char *argv[]) {
    std::vector<std::ifstream> streams;
    for (int i = 1; i < argc; ++i) {
        streams.emplace_back(argv[i]);
        std::string line;
        if (i != 1) getline(streams[i - 1], line);
    }
    std::ofstream out ("merged.csv");
    std::vector<std::string> categories;
    std::string line;
    getline(streams[0], line);
    std::stringstream ss(line);
    std::string word;
    while (getline(ss, word, ',')) {
        categories.push_back(word);
    }
    
    std::unordered_map<std::string, unsigned long long> st;
    unsigned long long number = 0;
    for (size_t i = 0; i < streams.size(); ++i) {
        std::string nline;
        while (getline(streams[i], nline)) {
            if (!st.count(nline)) {
                st.insert({nline, number++});
            }
        }
    }
    for (size_t i = 0; i < categories.size(); ++i) {
        out << categories[i];
        if (i != categories.size() - 1) out << ",";
        else out << std::endl;
    }

    std::map<unsigned long long, std::string> merged_map;
    for (auto &[str, number] : st) {
        merged_map[number] = str;
    }

    for (auto& [_, str] : merged_map) {
        out << str << std::endl;
    }
    for (size_t i = 0; i < streams.size(); ++i) {
        streams[i].close();
    }
    out.close();
}
        