#ifndef PEDIGREE_INDIVIDUAL_H
#define PEDIGREE_INDIVIDUAL_H

#include <vector>
#include <string>

struct IndividualId {
    std::string specimen;
    std::string country;
    bool is_male;
    unsigned long number;

    static IndividualId *of(const std::string& id_string);
};

struct IndividualIdCompare {
    bool operator()(const IndividualId *lhs, const IndividualId *rhs) const;
};

class Individual {
private:
    std::vector<Individual*> parents;
    std::vector<Individual*> children;
    IndividualId *id;
public:
    explicit Individual(IndividualId * id): id(id) {};

    Individual(IndividualId *id, Individual *mother, Individual *father);

    bool has_parents();

    void set_parents(Individual *father, Individual *mother);
};


#endif
