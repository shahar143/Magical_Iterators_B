//
// Created by super on 6/9/23.
//
#include "MagicalContainer.hpp"
using namespace ariel;

typedef std::vector<int>::size_type size_type;
typedef MagicalContainer::AscendingIterator AscendingIterator;

AscendingIterator::AscendingIterator(MagicalContainer &container)
: _container(container), current_index(0) {}

AscendingIterator::AscendingIterator(MagicalContainer &container, int index)
: _container(container), current_index(index) {}

AscendingIterator::AscendingIterator(const AscendingIterator& other)
: _container(other._container), current_index(other.current_index) {}

AscendingIterator AscendingIterator::begin() {
    return AscendingIterator(_container, 0);
}

AscendingIterator AscendingIterator::end() {
    return AscendingIterator(_container, _container.size());
}

int AscendingIterator::operator*() const {
    return _container.at((size_type)current_index);
}

bool AscendingIterator::operator==(const AscendingIterator& other) const {
    return current_index == other.current_index;
}

bool AscendingIterator::operator!=(const AscendingIterator& other) const {
    return !(*this == other);
}

bool AscendingIterator::operator<(const AscendingIterator& other) const {
    return current_index < other.current_index;
}

bool AscendingIterator::operator>(const AscendingIterator& other) const {
    return (current_index > other.current_index) && (*this != other);
}

AscendingIterator& AscendingIterator::operator++(){
    if(current_index >= _container.size()){
        throw std::runtime_error("out of range");
    }
    current_index++;
    return *this;
}

const AscendingIterator AscendingIterator::operator++(int){
    const AscendingIterator temp = AscendingIterator(*this);
    current_index++;
    return temp;
}

AscendingIterator& AscendingIterator::operator=(const AscendingIterator& other) {
    if(this->_container != other._container)
        throw std::runtime_error("SideCrossIterator: iterators are not from the same container");
    if (this != &other) {
        _container = other._container;
        current_index = other.current_index;
    }
    return *this;
}





