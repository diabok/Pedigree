#ifndef TWORCZOSC_MILOSZA_INDIVIDUAL_H
#define TWORCZOSC_MILOSZA_INDIVIDUAL_H


#include <vector>
#include <string>

class Individual {
private:
    std::vector<Individual*> parents;
    std::vector<Individual*> children;
    std::string id;
public:
    Individual(const std::vector<Individual *> &parents, const std::vector<Individual *> &children,
               const std::string &id);

    bool operator<(const Individual &rhs) const;

    bool operator>(const Individual &rhs) const;

    bool operator<=(const Individual &rhs) const;

    bool operator>=(const Individual &rhs) const;

    Individual(std::string id);

    Individual(std::vector<Individual *> parents, std::string id);

    bool has_parents();
};


#endif
