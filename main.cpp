#include <vector>
#include <iostream>
#include <chrono>
#include "Pedigree.h"
#include "PedigreeLoader.h"


int main([[maybe_unused]] int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <file_name>" << std::endl;
        return EXIT_FAILURE;
    }

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    Pedigree pedigree = PedigreeLoader::load(argv[1]);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Pedigree: " << pedigree.size() << std::endl;
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    return EXIT_SUCCESS;

}

