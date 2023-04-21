#include "HashMap.h"

int HashMap::hash(vstring key) const {
    int prime = 11;
    long long int hashValue = 0;
    for (int i = 0; i < key.size(); i++) {
        hashValue += (int) key[i] * prime;
        prime *= prime;
    }

    return (int) hashValue % sizeOfTable;
}

void HashMap::insert(const vstring &key, int value) {
    numberOfElements++;
    int index = hash(key);

    pair<vstring, int> newPair(key, value);
    main_table.i_element(index, true).push_back(newPair);
}

int HashMap::get(const vstring &key) {
    int index = hash(key);

    for (int i = 0; i < main_table.i_element(index, true).number_of_nodes; i++) {
        if (main_table.i_element(index, true)[i]->first == key) {
            return main_table.i_element(index, true)[i]->second;
        }
    }

    return -sizeOfTable;
}

void HashMap::remove(const vstring &key) {
    int index = hash(key);

    for (int i = 0; i < main_table.i_element(index, true).number_of_nodes; i++) {

        if (main_table.i_element(index, true)[i]->first == key) {
            main_table.i_element(index, true).pop_index(i);
            numberOfElements--;
            return;
        }
    }
}

bool HashMap::contains(const vstring &key) {
    int index = hash(key);

    for (int i = 0; i < main_table.i_element(index, true).number_of_nodes; i++) {
        if (main_table.i_element(index, true)[i]->first == key) {
            return true;
        }
    }

    return false;
}

int HashMap::size() const {
    return numberOfElements;
}
