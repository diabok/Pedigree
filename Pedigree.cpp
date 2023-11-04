//
// Created by marek on 29.10.23.
//

#include <iostream>
#include <chrono>
#include "Pedigree.h"


void Pedigree::add(IndividualId *id, IndividualId *father_id, IndividualId *mother_id) {
    create(id);
    create(father_id);
    create(mother_id);
}

void Pedigree::create(IndividualId *id) {
    if (id == nullptr) {
        return;
    } else if (!contains_id(id)) {
        auto *individual = new Individual(id);
        elements++;
        individuals[id] = individual;
        return;
    }
}

long Pedigree::size() const {
    return elements;
}

bool Pedigree::contains_id(IndividualId *id) { return individuals.contains(id); }

Pedigree::Pedigree(const std::vector<IndividualEntry> &entries) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (const auto &entry: entries) {
        add(entry.id, entry.father_id, entry.mother_id);
    }

    std::chrono::steady_clock::time_point end_create = std::chrono::steady_clock::now();
    // Link parents and children
    for (const auto &entry: entries) {
        link_parents(entry);
    }

    std::chrono::steady_clock::time_point end_link = std::chrono::steady_clock::now();
    // Find roots
    for (const auto &individual: individuals) {
        if (individual.first == nullptr)
            continue;
        if (!individual.second->has_parents()) {
            roots.insert(individual.second);
        }
    }

    std::chrono::steady_clock::time_point end_roots = std::chrono::steady_clock::now();

    std::cout << "Pedigree size: " << size() << std::endl;
    std::cout << "Create time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_create - begin).count() << "[ms]" << std::endl;
    std::cout << "Link time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_link - end_create).count() << "[ms]" << std::endl;
    std::cout << "Roots time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_roots - end_link).count() << "[ms]" << std::endl;
}

void Pedigree::link_parents(const IndividualEntry &entry) {
    Individual *individual = individuals[entry.id];
    Individual *father = individuals[entry.father_id];
    Individual *mother = individuals[entry.mother_id];

    individual->set_parents(father, mother);
}
