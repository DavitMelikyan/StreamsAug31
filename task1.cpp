#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>

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
    
    std::unordered_set<std::string> st;
    for (size_t i = 0; i < streams.size(); ++i) {
        std::string nline;
        while (getline(streams[i], nline)) {
            st.insert(nline);
        }
    }
    for (size_t i = 0; i < categories.size(); ++i) {
        out << categories[i];
        if (i != categories.size() - 1) out << ",";
        else out << std::endl;
    }

    for (auto& it : st) {
        out << it << std::endl;
    }
    for (size_t i = 0; i < streams.size(); ++i) {
        streams[i].close();
    }
    out.close();
}
        