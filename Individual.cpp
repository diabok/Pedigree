#include <regex>
#include "Individual.h"


Individual::Individual(IndividualId *id, Individual *mother, Individual *father) : id(id) {
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

IndividualId *IndividualId::of(const std::string &id_string) {
    const static std::regex id_pattern("([A-Z]{3})([A-Z]{3})([FM])([0-9]{12})");
    std::smatch match;
    std::regex_match(id_string, match, id_pattern);

    if (match.empty()) {
        return nullptr;
    }

    return new IndividualId(
            match[1],
            match[2],
            match[3] == "M",
            std::stoul(match[4])
    );
}

bool IndividualIdCompare::operator()(const IndividualId *lhs, const IndividualId *rhs) const {
    if (rhs == nullptr) {
        return false;
    } else if (lhs == nullptr) {
        return true;
    }
    // Comparison order: number, is_male, country, specimen

    if (lhs->number != rhs->number) {
        return lhs->number < rhs->number;
    } else if (lhs->is_male != rhs->is_male) {
        return lhs->is_male;
    } else if (lhs->country != rhs->country) {
        return lhs->country < rhs->country;
    } else {
        return lhs->specimen < rhs->specimen;
    }
}
