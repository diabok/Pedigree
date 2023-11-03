#ifndef PEDIGREE_INDIVIDUAL_H
#define PEDIGREE_INDIVIDUAL_H

#include <vector>
#include <string>

class IndividualBase {
private:
    std::string id;
public:
    explicit IndividualBase(std::string id): id(std::move(id)) {};
    bool operator==(const IndividualBase &rhs) const;
    [[nodiscard]] const std::string &get_id() const;
};

struct IndividualHash {
    std::size_t operator()(const IndividualBase * individual) const {
        return std::hash<std::string>()(individual->get_id());
    }
};

struct IndividualEquals {
    bool operator()(const IndividualBase * lhs, const IndividualBase * rhs) const {
        return lhs->get_id() == rhs->get_id();
    }
};

class Individual: public IndividualBase {
private:
    std::vector<Individual*> parents;
    std::vector<Individual*> children;
    std::string id;
public:
    explicit Individual(std::string id): IndividualBase(std::move(id)) {};

    Individual(const std::string& id, Individual *mother, Individual *father);

    bool has_parents();

    void set_parents(Individual *father, Individual *mother);
};


#endif
