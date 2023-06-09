//
// Created by super on 5/25/23.
//

#include "MagicalContainer.hpp"
#include <iostream>
#include <vector>
using namespace std;
using namespace ariel;

typedef std::vector<int>::size_type size_type;

MagicalContainer::MagicalContainer(): int_container(0), prime_indexes(0) {}

MagicalContainer::MagicalContainer(const MagicalContainer &other)
: int_container(other.int_container), prime_indexes(other.prime_indexes) {}

int MagicalContainer::size() const {
    return int_container.size();
}

int MagicalContainer::p_size() const {
    return prime_indexes.size();
}

int MagicalContainer::at(size_type elm) const {
    return int_container.at(elm);
}

int MagicalContainer::p_at(size_type elm) const {
    return prime_indexes.at(elm);
}

bool isPrime(int num){
    if (num < 2){
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

void MagicalContainer::addElement(int elm) {
    auto it = lower_bound(int_container.begin(), int_container.end(), elm);
    int_container.insert(it, elm);
    int counter = 0;
    prime_indexes.clear();
    for(auto element : int_container){
        if(isPrime(element)){
            prime_indexes.push_back(counter);
        }
        counter++;
    }
}

int MagicalContainer::removeElement(int elm) {
    auto it = lower_bound(int_container.begin(), int_container.end(), elm);
    if(it == int_container.end()){
        throw runtime_error("Element not found");
    }
    if(isPrime(elm)){
        int counter = 0;
        for(auto element : int_container){
            if(element != elm) counter++;
            else break;
        }
        auto it_prime = lower_bound(prime_indexes.begin(), prime_indexes.end(), counter);
        prime_indexes.erase(it_prime);
    }
    if(*it == elm){
        int_container.erase(it);
        return 1;
    }
    return 0;
}

void MagicalContainer::print() {
    cout << "int_container: ";
    for (auto element : int_container) {
        cout << element << " ";
    }
    cout << endl;
}

bool MagicalContainer::operator==(const MagicalContainer& other) const {
    return (int_container == other.int_container) && (prime_indexes == other.prime_indexes);
}

bool MagicalContainer::operator!=(const MagicalContainer& other) const {
    return !(*this == other);
}

MagicalContainer& MagicalContainer::operator=(const MagicalContainer& other) {
    if (this != &other) {
        int_container = other.int_container;
        prime_indexes = other.prime_indexes;
    }
    return *this;
}