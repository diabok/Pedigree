#include "Individual.h"
#include <utility>


Individual::Individual(std::string id) {
    this->id = std::move(id);
}

Individual::Individual(const std::string& id, Individual *mother, Individual *father): Individual(id) {
    set_parents(father, mother);
}

bool Individual::has_parents() {
    return !parents.empty();
}

void Individual::set_parents(Individual *father, Individual *mother) {
    if (father != nullptr) {
        father->children.push_back(this);
        this->parents.push_back(father);
    }

    if (mother != nullptr) {
        mother->children.push_back(this);
        this->parents.push_back(mother);
    }
}
