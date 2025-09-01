#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <filesystem>

std::ofstream out ("app.log");

void f(const std::string& filename, size_t filesize, size_t archivecount) {
    static int count = 0;
    if (std::filesystem::file_size("app.log") >= filesize) {
        ++count;
        std::filesystem::rename("app.log", "app" + std::to_string(count) + "log");
        std::ofstream tmp ("app.log");
        out = std::move(tmp);
        if (count > archivecount) {
            std::filesystem::remove("app" + std::to_string(count - archivecount) + ".log");
        }
    }
}

int main() {
    int a = 0;
    while (std::cin >> a) {
        out << "logloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglog" << std::endl << "loglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglog" << std::endl << "loglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglog" << std::endl << "logloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglogloglog";
        f("app.log", 100, 5);
    }
    
}