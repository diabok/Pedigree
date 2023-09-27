#include "Individual.h"
#include "algorithm"
#include <utility>

Individual::Individual(const std::vector<Individual *> &parents, const std::vector<Individual *> &children,
                       const std::string &id) : parents(parents), children(children), id(id) {
    this->parents = parents;
    this->children = children;
    this->id = id;
}

bool Individual::operator<(const Individual &rhs) const {
    return id < rhs.id;
}

bool Individual::operator>(const Individual &rhs) const {
    return rhs < *this;
}

bool Individual::operator<=(const Individual &rhs) const {
    return !(rhs < *this);
}

bool Individual::operator>=(const Individual &rhs) const {
    return !(*this < rhs);
}

Individual::Individual(std::string id) {
    this->id = std::move(id);
    this->parents = std::vector<Individual*>();
    this->children = std::vector<Individual*>();
}

Individual::Individual(std::vector<Individual *> parents, std::string id) {
    this->parents = std::move(parents);
    this->id = std::move(id);
    this->children = std::vector<Individual*>();
    std::for_each(this->parents.begin(), this->parents.end(), [&](const auto &item) {
        item->children.push_back(this);
    });
}

bool Individual::has_parents() {
    return !this->parents.empty();
}
