//
// Created by marek on 29.10.23.
//

#ifndef TWORCZOSC_MILOSZA_PEDIGREE_H
#define TWORCZOSC_MILOSZA_PEDIGREE_H


#include <string>
#include <map>
#include <set>
#include "Individual.h"

class Pedigree {

public:
    [[nodiscard]] long size() const;
    void add(const std::string& id, const std::string& father_id, const std::string& mother_id);
private:
    Individual *create_or_get(const std::string &id);
    std::map<std::string, Individual*> individuals;
    std::set<Individual*> roots;
    long elements = 0;

    bool contains_id(const std::string &id);

    static bool is_empty_id(const std::string &id) ;

    bool is_root(Individual *individual);
};


#endif //TWORCZOSC_MILOSZA_PEDIGREE_H
