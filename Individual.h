#ifndef PEDIGREE_INDIVIDUAL_H
#define PEDIGREE_INDIVIDUAL_H

#include <vector>
#include <string>

class Individual {
private:
    std::vector<Individual*> parents;
    std::vector<Individual*> children;
    std::string id;
public:
    explicit Individual(std::string id);

    Individual(const std::string& id, Individual *mother, Individual *father);

    bool has_parents();

    void set_parents(Individual *father, Individual *mother);
};


#endif
