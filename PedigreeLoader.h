//
// Created by marek on 29.10.23.
//

#ifndef TWORCZOSC_MILOSZA_PEDIGREELOADER_H
#define TWORCZOSC_MILOSZA_PEDIGREELOADER_H


#include <string>
#include "Pedigree.h"

class PedigreeLoader {
private:
    explicit PedigreeLoader(const std::string& path);
    std::string path;
    Pedigree load();
public:
    static Pedigree load(const std::string& path);
};


#endif //TWORCZOSC_MILOSZA_PEDIGREELOADER_H
