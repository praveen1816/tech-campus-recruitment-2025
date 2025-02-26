#include <iostream>
#include <fstream>
#include <string>

void extract_logs(const std::string& log_file, const std::string& date) {
    std::string output_file = "output/output_" + date + ".txt";

    std::ifstream infile(log_file);
    std::ofstream outfile(output_file);

    if (!infile.is_open()) {
        std::cerr << "Error: Could not open log file.\n";
        return;
    }

    if (!outfile.is_open()) {
        std::cerr << "Error: Could not create output file.\n";
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {
        if (line.compare(0, date.length(), date) == 0) {  // Check if the line starts with the given date
            outfile << line << "\n";
        }
    }

    std::cout << "Logs for " << date << " saved in " << output_file << "\n";
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./extract_logs <log_2024> <2024-12-01>\n";
        return 1;
    }

    extract_logs(argv[1], argv[2]);
    return 0;
}