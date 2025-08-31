#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

int main() {
    std::ifstream in ("task2.cfg");
    std::ifstream file ("task2.txt");
    std::ofstream out ("task2answ.txt");
    std::unordered_map<std::string, std::string> mp;
    std::string line;
    while (getline(in, line)) {
        std::stringstream ss(line);
        std::string word;
        std::string category;
        ss >> category;
        getline(ss, line, '=');
        ss >> word;
        mp[category] = word;
    }

    while (getline(file, line)) {
        std::stringstream ss(line);
        int countc;
        std::string word;
        out << mp["prefix"];
        while (ss >> word) {
            if (mp["uppercase"] == "all") {
                std::transform(word.begin(), word.end(), word.begin(), ::toupper);
            } else if (mp["uppercase"] == "title") {
                word[0] &= 223;
            }
            countc += word.size();
            if (countc > std::stoull(mp["wrap"])) {
                countc = word.size();
                out << std::endl;
                out << mp["prefix"];
                out << word << " ";
                break;
            }
            out << word << " ";
        }
        out << std::endl;
    }
    in.close();
    out.close();
}