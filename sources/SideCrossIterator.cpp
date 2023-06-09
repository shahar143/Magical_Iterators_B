//
// Created by super on 6/9/23.
//

#include "MagicalContainer.hpp"
using namespace ariel;

typedef std::vector<int>::size_type size_type;
typedef MagicalContainer::SideCrossIterator SideCrossIterator;

SideCrossIterator::SideCrossIterator(MagicalContainer& container)
: _container(container), start_or_end(false), index_from_end(container.size()), index_from_start(0), current_index(0) {}

SideCrossIterator::SideCrossIterator(MagicalContainer& container, int index)
: _container(container), current_index(index), index_from_end(container.size()), index_from_start(0) {}

SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
: _container(other._container), current_index(other.current_index), index_from_end(other.index_from_end),
index_from_start(other.index_from_start) {}

SideCrossIterator SideCrossIterator::begin() {
    return SideCrossIterator(_container, 0);
}

SideCrossIterator SideCrossIterator::end() {
    return SideCrossIterator(_container, _container.size());
}

int SideCrossIterator::operator*() const {
    return _container.at((size_type)current_index);
}

bool SideCrossIterator::operator==(const SideCrossIterator &other) const {
    return current_index == other.current_index;
}

bool SideCrossIterator::operator!=(const SideCrossIterator &other) const {
    return !(*this == other);
}

bool SideCrossIterator::operator<(const SideCrossIterator &other) const {
    return current_index < other.current_index;
}

bool SideCrossIterator::operator>(const SideCrossIterator &other) const {
    return (current_index > other.current_index) && (*this != other);
}

const SideCrossIterator SideCrossIterator::operator++(int) {
    const SideCrossIterator sci = SideCrossIterator(*this);
    ++(*this);
    return sci;
}

SideCrossIterator& SideCrossIterator::operator++() {
    if(current_index >= _container.size()){
        throw std::runtime_error("SideCrossIterator: iterator out of range");
    }
    if(index_from_end != index_from_start + 1){
        if(start_or_end){ //in right side
            index_from_start++;
            current_index = index_from_start;
            start_or_end = false;
        }
        else{
            index_from_end--;
            current_index = index_from_end;
            start_or_end = true;
        }
        return *this;
    }
    else{
        current_index = _container.size();
        return *this;
    }
}

SideCrossIterator& SideCrossIterator::operator=(const SideCrossIterator &other) {
    if(this->_container != other._container)
        throw std::runtime_error("SideCrossIterator: iterators are not from the same container");
    _container = other._container;
    start_or_end = other.start_or_end;
    index_from_start = other.index_from_start;
    index_from_end = other.index_from_end;
    current_index = other.current_index;
    return *this;
}