//
// Created by marek on 29.10.23.
//

#ifndef TWORCZOSC_MILOSZA_PEDIGREE_H
#define TWORCZOSC_MILOSZA_PEDIGREE_H


#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include "Individual.h"
#include "IndividualEntry.h"

class Pedigree {

public:
    explicit Pedigree(const std::vector<IndividualEntry>& entries);

    [[nodiscard]] long size() const;
private:
    std::map<IndividualId*, Individual*, IndividualIdCompare> individuals;
    std::set<Individual*> roots;
    long elements = 0;

    void create(IndividualId *id);

    void add(IndividualId *id, IndividualId *father_id, IndividualId *mother_id);

    bool contains_id(IndividualId *id);

    void link_parents(const IndividualEntry &entry);
};


#endif //TWORCZOSC_MILOSZA_PEDIGREE_H
