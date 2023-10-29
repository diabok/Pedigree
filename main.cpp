#include <vector>
#include <iostream>
#include "Pedigree.h"
#include "PedigreeLoader.h"


int main([[maybe_unused]] int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <file_name>" << std::endl;
        return EXIT_FAILURE;
    }

    Pedigree pedigree = PedigreeLoader::load(argv[1]);

    std::cout << "Pedigree: " << pedigree.size() << std::endl;

    return EXIT_SUCCESS;

}

