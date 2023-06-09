//
// Created by super on 6/9/23.
//

#include "MagicalContainer.hpp"
using namespace ariel;

typedef std::vector<int>::size_type size_type;
typedef MagicalContainer::PrimeIterator PrimeIterator;

PrimeIterator::PrimeIterator(MagicalContainer& container): _container(container), current_index(0) {}

PrimeIterator::PrimeIterator(MagicalContainer& container, int index): _container(container), current_index(index) {}

PrimeIterator::PrimeIterator(const PrimeIterator& other): _container(other._container), current_index(other.current_index) {}

PrimeIterator PrimeIterator::begin() {
    return PrimeIterator(_container, 0);
}

PrimeIterator PrimeIterator::end() {
    return PrimeIterator(_container, _container.p_size());
}

int PrimeIterator::operator*() const {
    if (current_index < _container.p_size()) {
        return _container.at((size_type)_container.p_at((size_type)current_index));
    }
    throw std::out_of_range("PrimeIterator: iterator out of range");
}

bool PrimeIterator::operator==(const PrimeIterator &other) const {
    return current_index == other.current_index;
}

bool PrimeIterator::operator!=(const PrimeIterator &other) const {
    return !(*this == other);
}

bool PrimeIterator::operator<(const PrimeIterator& other) const {
    return current_index < other.current_index;
}

bool PrimeIterator::operator>(const PrimeIterator& other) const {
    return (current_index > other.current_index) && (*this != other);
}

const PrimeIterator PrimeIterator::operator++(int) {
    const PrimeIterator temp = PrimeIterator(*this);
    current_index++;
    return temp;
}

PrimeIterator& PrimeIterator::operator++() {
    if(current_index >= _container.p_size()){
        throw std::runtime_error("SideCrossIterator: iterator out of range");
    }
    current_index++;
    return *this;
}

PrimeIterator& PrimeIterator::operator=(const PrimeIterator& other) {
    if(this->_container != other._container)
        throw std::runtime_error("PrimeIterator: iterators are not from the same container");
    if (this != &other) {
        _container = other._container;
        current_index = other.current_index;
    }
    return *this;
}




