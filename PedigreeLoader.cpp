//
// Created by marek on 29.10.23.
//

#include <fstream>
#include <regex>
#include <iostream>
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

    while (!file.eof()) {
        std::string line;
        std::getline(file, line, '\n');

        // pattern: id father_id mother_id
        // id format 0|([A-Z]{3}[A-Z]{3}[FM][0-9]{12})
        // example HOLPOLF012345678901

        const std::regex line_pattern("([A-Z]{3}[A-Z]{3}[FM][0-9]{12}) (0|([A-Z]{3}[A-Z]{3}[FM][0-9]{12})) (0|([A-Z]{3}[A-Z]{3}[FM][0-9]{12}))");
        std::smatch match;
        if (std::regex_match(line, match, line_pattern)) {

            std::string id = match[1];
            std::string father_id = match[2];
            std::string mother_id = match[4];

            entries.emplace_back(id, father_id, mother_id);
        } else {
            std::cout << "No match: " << line << std::endl;
        }
    }

    return Pedigree(entries);
}
