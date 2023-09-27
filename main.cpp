#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <iostream>
#include "Individual.h"


std::vector<Individual *> sort_traverse(std::vector<Individual *> parents);

Individual *create_or_get(std::map<std::string, Individual *> map, std::string id);

std::vector<Individual*> load_data(const std::string &file_name) {
    std::vector<Individual*> result;
    std::map<std::string, Individual*> id_to_individual_map;
    std::ifstream file(file_name);
    
    while(!file.eof()) {
        std::string line;
        std::getline(file, line, '\n');
        
        std::string id, parent_m_id, parent_f_id;
        std::istringstream iss(line);
        iss >> id >> parent_m_id >> parent_f_id;
        Individual* parent_m = create_or_get(id_to_individual_map, parent_m_id);
        Individual* parent_f = create_or_get(id_to_individual_map, parent_f_id);
        std::vector<Individual*> parents;
        if (parent_m != nullptr) {
            parents.push_back(parent_m);
        }
        if (parent_f != nullptr) {
            parents.push_back(parent_f);
        }
        auto* individual = new Individual(parents, id);
        id_to_individual_map[id] = individual;
        if (!individual->has_parents()) {
            result.push_back(individual);
        }
        std::for_each(id_to_individual_map.begin(), id_to_individual_map.end(), [&](const auto &item) {
            if (!item.second->has_parents()) {
                result.push_back(item.second);
            }
        });
    }

    return result;
}

Individual *create_or_get(std::map<std::string, Individual *> map, std::string id) {
    if (id == "0") {
        return nullptr;
    }
    if(map.find(id) != map.end()) {
        return map[id];
    }
    Individual *result = new Individual(id);
    map[id] = result;
    return result;
}

int main([[maybe_unused]] int argc, char *argv[]) {
    std::vector<Individual*> parents = load_data(argv[1]);

    std::vector<Individual*> sorted = sort_traverse(parents);

    return EXIT_SUCCESS;

}

std::vector<Individual *> sort_traverse(std::vector<Individual *> parents) {
    const std::vector<Individual *> result;
    /*
     * 1. Zainicjować kolekcje:
		1. `set<string> sorted_ids`
		2. `vector<Individual> sorted`
		3. `vector<Individual> to_be_sorted <- parents.values`
	2. Dopóki `to_be_sorted.size() > 0`
		1. `obj <- to_be_sorted.pop()`
		2. jeżeli `obj.parents` są w `sorted_ids`
			1. tak ->
				1. `sorted.push_back(obj)`
				2. `to_be_sorted.push_back(...obj.children)`
			2. nie -> skip
     */
    return result;
}
