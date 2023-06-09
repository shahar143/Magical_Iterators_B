//
// Created by super on 5/25/23.
//

#ifndef MAGICAL_ITERATORS_MAGICALCONTAINER_H
#define MAGICAL_ITERATORS_MAGICALCONTAINER_H
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

/**
 * I've created a short alias for the unsigned long type
 */
typedef std::vector<int>::size_type size_type;

namespace ariel{
    class MagicalContainer {
        /**
         * The container is implemented as a vector of integers
         * The prime_indexes vector is used to store the indexes of the prime numbers in the container. This improves
         * the concept of saving pointers to the prime numbers in the container, because the indexes size is much smaller
         * than the size of a pointer.
         */
        vector<int> int_container;
        vector<int> prime_indexes;
    public:
        /**
         * The default constructor
         * Initializes the container and the prime_indexes vectors to be empty
         */
        MagicalContainer();

        /**
         * The copy constructor
         * @param other The MagicalContainer to copy
         */
        MagicalContainer(const MagicalContainer &other);

        /**
         * For the rule of 5
         */
        virtual ~MagicalContainer() = default;
        MagicalContainer(MagicalContainer &&other) = delete;
        MagicalContainer &operator=(MagicalContainer &&other) = delete;

        /**
         * @brief Returns the size of the int_container vector - the main vector of the integers in the container
         * @return int - the size of the container
         */
        int size() const;

        /**
         * @brief Returns the size of the prime_indexes vector
         * @return int - the size of the prime_indexes vector
         */
        int p_size() const;

        /**
         * @brief Returns the element in the index elm in the int_container vector
         * @param elm The index of the element to return
         * @return int - the element in the index elm in the int_container vector
         */
        int at(size_type elm) const;

        /**
         * @brief Returns the element in the index elm in the int_container vector, according to the prime_indexes vector.
         * This function iterates over the prime numbers only in the container
         * @param elm The index of the element to return
         * @return int - the element in the index elm in the int_container vector
         */
        int p_at(size_type elm) const;

        /**
         * @brief Adds an element to the container
         * @param elm The element to add
         * @complexity O(n)
         */
        void addElement(int elm);

        /**
         * @brief Removes an element from the container
         * @param elm The element to remove
         * @return int - the number of elements removed
         * @complexity O(log(n))
         */
        int removeElement(int elm);

        /**
         * @brief Prints the container (only the int_container vector)
         */
        void print();

        /**
         * @brief Overloading the == operator to compare between two MagicalContainers
         * @param other - The MagicalContainer to compare to
         * @return true if the two containers are equal, false otherwise
         */
        bool operator==(const MagicalContainer& other) const;

        /**
         * @brief Overloading the != operator to compare between two MagicalContainers
         * @param other - The MagicalContainer to compare to
         * @return true if the two containers are not equal, false otherwise
         */
        bool operator!=(const MagicalContainer& other) const;

        /**
         * @brief Overloading the = operator to assign a MagicalContainer to another MagicalContainer
         * @param other - The MagicalContainer to assign to
         * @return MagicalContainer& - The assigned MagicalContainer
         */
        MagicalContainer& operator=(const MagicalContainer& other);

        /**
         * @brief AscendingIterator class - an iterator that iterates over the container in an ascending order
         */
        class AscendingIterator {
            /**
             * The iterator is implemented as an index to the container
             * It's fields are:
             * _container - a reference to the MagicalContainer that the iterator iterates over
             * current_index - the index of the iterator in the container
             */
            MagicalContainer& _container;
            int current_index;

            AscendingIterator(MagicalContainer &container, int index);
        public:
            AscendingIterator(MagicalContainer& container);

            AscendingIterator(const AscendingIterator& other);

            ~AscendingIterator() = default;
            AscendingIterator(AscendingIterator&& other) = default;
            AscendingIterator& operator=(AscendingIterator&& other) = delete;

            AscendingIterator begin();

            AscendingIterator end();

            int operator*() const;

            bool operator==(const AscendingIterator& other) const;

            bool operator!=(const AscendingIterator& other) const;

            bool operator<(const AscendingIterator& other) const;

            bool operator>(const AscendingIterator& other) const;

            AscendingIterator& operator++(); // prefix

            const AscendingIterator operator++(int); // postfix

            AscendingIterator& operator=(const AscendingIterator& other);
        };

        class PrimeIterator {
            MagicalContainer& _container;
            int current_index;

            PrimeIterator(MagicalContainer& container, int index);
        public:
            PrimeIterator(MagicalContainer& container);

            PrimeIterator(const PrimeIterator& other);

            ~PrimeIterator() = default;
            PrimeIterator(PrimeIterator&& other) = default;
            PrimeIterator& operator=(PrimeIterator&& other) = delete;

            PrimeIterator begin();

            PrimeIterator end();

            int operator*() const;

            bool operator==(const PrimeIterator& other) const;

            bool operator!=(const PrimeIterator& other) const;

            bool operator<(const PrimeIterator& other) const;

            bool operator>(const PrimeIterator& other) const;

            PrimeIterator& operator++(); // prefix

            const PrimeIterator operator++(int); // postfix

            PrimeIterator& operator=(const PrimeIterator& other);
        };


        class SideCrossIterator {
            MagicalContainer& _container;
            bool start_or_end;
            int index_from_start;
            int index_from_end;
            int current_index;

            SideCrossIterator(MagicalContainer& container, int index);
        public:
            SideCrossIterator(MagicalContainer& container);

            SideCrossIterator(const SideCrossIterator& other);

            ~SideCrossIterator() = default;
            SideCrossIterator(SideCrossIterator&& other) = default;
            SideCrossIterator& operator=(SideCrossIterator&& other) = delete;

            SideCrossIterator begin();

            SideCrossIterator end();

            int operator*() const;

            bool operator==(const SideCrossIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            const SideCrossIterator operator++(int); // postfix

            SideCrossIterator& operator++(); // prefix

            SideCrossIterator& operator=(const SideCrossIterator &other);

        };

    };
}

#endif //MAGICAL_ITERATORS_MAGICALCONTAINER_H
