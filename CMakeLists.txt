cmake_minimum_required(VERSION 3.26)
project(tworczosc_milosza)

set(CMAKE_CXX_STANDARD 23)

add_executable(tworczosc_milosza main.cpp
        Individual.cpp
        Individual.h
        Pedigree.cpp
        Pedigree.h
        PedigreeLoader.cpp
        PedigreeLoader.h
        IndividualEntry.h)
