#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::ifstream in ("task4.txt");
    std::ofstream out ("task4answ.csv");
    std::string line;
    out << "ID,Name,DOB\n";
    while (getline(in, line)) {
        std::string id = line.substr(0,4);
        std::string fullName = line.substr(4, 13);
        std::string dob = line.substr(17, 8);
        std::stringstream ss(fullName);
        std::string name;
        std::string surname;
        ss >> name;
        ss >> surname;
        std::string year = dob.substr(0,4);
        std::string month = dob.substr(4,2);
        std::string day = dob.substr(6,2);
        int iid = std::stoi(id);
        out << iid << "," << name << " " << surname << "," << year << "-" << month << "-" << day << std::endl;
    }
    in.close();
    out.close();
}
