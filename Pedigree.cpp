//
// Created by marek on 29.10.23.
//

#include <iostream>
#include "Pedigree.h"


void Pedigree::add(const std::string &id, const std::string &father_id, const std::string &mother_id) {
    Individual *father = create_or_get(father_id);
    Individual *mother = create_or_get(mother_id);
    if (!contains_id(id)) {
        auto *individual = new Individual(id, father, mother);
        elements++;
        individuals.insert(individual);

        if (!individual->has_parents()) {
            roots.insert(individual);
        }
    } else {
        auto *key_ref = new IndividualBase(id);
        Individual *individual = (Individual *) *individuals.find(key_ref);
        if (!individual->has_parents()) {
            individual->set_parents(father, mother);
            if (is_root(individual)) {
                roots.erase(individual);
            }
        } else {
            std::cout << "Individual " << id << " already has parents" << std::endl;
        }
    }
}

Individual *Pedigree::create_or_get(const std::string &id) {
    if (is_empty_id(id)) {
        return nullptr;
    } else if (!contains_id(id)) {
        auto *individual = new Individual(id);
        elements++;
        individuals.insert(individual);
        return individual;
    }

    return (Individual *) *individuals.find(new IndividualBase(id));
}

bool Pedigree::is_empty_id(const std::string &id) { return id == "0"; }

long Pedigree::size() const {
    return elements;
}

bool Pedigree::is_root(Individual *individual) { return roots.find(individual) != roots.end(); }

bool Pedigree::contains_id(const std::string &id) { return individuals.contains(new IndividualBase(id)); }

Pedigree::Pedigree(const std::vector<IndividualEntry>& entries) {
    for (const auto &entry : entries) {
        add(entry.id, entry.father_id, entry.mother_id);
    }
}
