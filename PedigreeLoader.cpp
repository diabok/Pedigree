//
// Created by marek on 29.10.23.
//

#include <fstream>
#include <regex>
#include <iostream>
#include <chrono>
#include "PedigreeLoader.h"
#include "IndividualEntry.h"

Pedigree PedigreeLoader::load(const std::string &path) {
    PedigreeLoader loader(path);
    return loader.load();
}

PedigreeLoader::PedigreeLoader(const std::string &path) {
    this->path = path;
}

Pedigree PedigreeLoader::load() {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + path);
    }
    std::vector<IndividualEntry> entries;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    // pattern: id father_id mother_id
    // id format 0|([A-Z]{3}[A-Z]{3}[FM][0-9]{12})
    // example HOLPOLF012345678901
    const std::regex line_pattern(
            "([A-Z]{3}[A-Z]{3}[FM][0-9]{12}) (0|([A-Z]{3}[A-Z]{3}[FM][0-9]{12})) (0|([A-Z]{3}[A-Z]{3}[FM][0-9]{12}))");
    std::smatch match;
    while (!file.eof()) {
        std::string line;
        std::getline(file, line, '\n');

        if (std::regex_match(line, match, line_pattern)) {
            IndividualId *id = IndividualId::of(match[1]);
            IndividualId *father_id = IndividualId::of(match[2]);
            IndividualId *mother_id = IndividualId::of(match[4]);

            entries.emplace_back(id, father_id, mother_id);
        } else {
            std::cout << "No match: " << line << std::endl;
        }
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "File read time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count()
              << "[ms]" << std::endl;

    return Pedigree(entries);
}
