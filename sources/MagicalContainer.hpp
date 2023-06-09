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

            /**
             * @brief A private constructor for the AscendingIterator class
             * @param container - a reference to the MagicalContainer that the iterator iterates over
             * @param index - an index of an int in the container. the iterator will point on this index
             * @throws out_of_range if the index is out of range
             */
            AscendingIterator(MagicalContainer &container, int index);
        public:
            /**
             * @brief A constructor for the AscendingIterator class
             * @param container - a reference to the MagicalContainer that the iterator iterates over
             * At the beginning, the iterator will point to the first element in the container
             */
            AscendingIterator(MagicalContainer& container);

            /**
             * @brief A copy constructor for the AscendingIterator class
             * @param other - the AscendingIterator to copy
             */
            AscendingIterator(const AscendingIterator& other);

            /**
             * For the rule of 5
             */
            ~AscendingIterator() = default;
            AscendingIterator(AscendingIterator&& other) = default;
            AscendingIterator& operator=(AscendingIterator&& other) = delete;

            /**
             * @brief Returns an iterator to the first element in the container
             * @return AscendingIterator - an iterator to the first element in the container
             */
            AscendingIterator begin();

            /**
             * @brief Returns an iterator to the last element in the container
             * @return AscendingIterator - an iterator to the last element in the container
             */
            AscendingIterator end();

            /**
             * @brief Returns the element in the current index of the iterator
             * @return int - the element in the current index of the iterator
             */
            int operator*() const;

            /**
             * @brief Overloading the == operator to compare between two AscendingIterators
             * @param other - The AscendingIterator to compare to
             * @return true if the two iterators are equal, false otherwise
             */
            bool operator==(const AscendingIterator& other) const;

            /**
             * @brief Overloading the != operator to compare between two AscendingIterators
             * @param other - The AscendingIterator to compare to
             * @return true if the two iterators are not equal, false otherwise
             * @complexity O(1)
             */
            bool operator!=(const AscendingIterator& other) const;

            /**
             * @brief Overloading the < operator to compare between two AscendingIterators
             * @param other - The AscendingIterator to compare to
             * @return true if the current iterator is smaller than the other iterator, false otherwise
             */
            bool operator<(const AscendingIterator& other) const;

            /**
             * @brief Overloading the > operator to compare between two AscendingIterators
             * @param other - The AscendingIterator to compare to
             * @return true if the current iterator is bigger than the other iterator, false otherwise
             */
            bool operator>(const AscendingIterator& other) const;

            /**
             * @brief Overloading the ++ operator to increase the iterator by 1
             * @return AscendingIterator& - the iterator after the increase
             * @throws out_of_range when trying to increment an iterator when it's at the end of the container
             * @complexity O(1)
             */
            AscendingIterator& operator++(); // prefix

            /**
             * @brief Overloading the ++ operator to increase the iterator by 1
             * @return AscendingIterator - the iterator before the increase
             * @throws out_of_range when trying to increment an iterator when it's at the end of the container
             * @complexity O(1)
             */
            const AscendingIterator operator++(int); // postfix

            /**
             * @brief Overloading the = operator to assign an AscendingIterator to another AscendingIterator
             * @param other - The AscendingIterator to assign to
             * @return AscendingIterator& - The assigned AscendingIterator
             */
            AscendingIterator& operator=(const AscendingIterator& other);
        };

        /**
         * @brief PrimeIterator class - an iterator that iterates over all the prime numbers in the container
         */
        class PrimeIterator {
            /**
             * The iterator is implemented as an index to the container
             * The prime index is the index of the prime number in the container. For example, if the container contains
             * [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] then the prime indexes are [1, 2, 4, 6]
             * current index = 0 in the iterator means that the iterator will actually point to int_container[1] = 2
             * It's fields are:
             * _container - a reference to the MagicalContainer that the iterator iterates over
             * current_index - the index of the iterator in the container
             */
            MagicalContainer& _container;
            int current_index;

            /**
             * @brief A private constructor for the PrimeIterator class
             * @param container - a reference to the MagicalContainer that the iterator iterates over
             * @param index - an index of an int in the container. the iterator will point on this index
             * @throws out_of_range if the index is out of range
             */
            PrimeIterator(MagicalContainer& container, int index);
        public:
            /**
             * @brief A constructor for the PrimeIterator class
             * @param container - a reference to the MagicalContainer that the iterator iterates over
             * At the beginning, the iterator will point to the first prime number in the container
             */
            PrimeIterator(MagicalContainer& container);

            /**
             * @brief A copy constructor for the PrimeIterator class
             * @param other - the PrimeIterator to copy
             */
            PrimeIterator(const PrimeIterator& other);

            /**
             * For the rule of 5
             */
            ~PrimeIterator() = default;
            PrimeIterator(PrimeIterator&& other) = default;
            PrimeIterator& operator=(PrimeIterator&& other) = delete;

            /**
             * @brief Returns an iterator to the first prime number in the container
             * @return PrimeIterator - an iterator to the first prime number in the container
             */
            PrimeIterator begin();

            /**
             * @brief Returns an iterator to the last prime number in the container
             * @return PrimeIterator - an iterator to the last prime number in the container
             */
            PrimeIterator end();

            /**
             * @brief Returns the prime number in the current index of the iterator
             * @return int - the prime number in the current index of the iterator
             */
            int operator*() const;

            /**
             * @brief Overloading the == operator to compare between two PrimeIterators
             * @param other - The PrimeIterator to compare to
             * @return true if the two iterators are equal, false otherwise
             */
            bool operator==(const PrimeIterator& other) const;

            /**
             * @brief Overloading the != operator to compare between two PrimeIterators
             * @param other - The PrimeIterator to compare to
             * @return true if the two iterators are not equal, false otherwise
             */
            bool operator!=(const PrimeIterator& other) const;

            /**
             * @brief Overloading the < operator to compare between two PrimeIterators
             * @param other - The PrimeIterator to compare to
             * @return true if the current iterator is smaller than the other iterator, false otherwise
             */
            bool operator<(const PrimeIterator& other) const;

            /**
             * @brief Overloading the > operator to compare between two PrimeIterators
             * @param other - The PrimeIterator to compare to
             * @return true if the current iterator is bigger than the other iterator, false otherwise
             */
            bool operator>(const PrimeIterator& other) const;

            /**
             * @brief Overloading the ++ operator to increase the iterator by 1
             * @return PrimeIterator& - the iterator after the increase
             * @throws out_of_range when trying to increment an iterator when it's at the end of the container
             * @complexity O(1)
             */
            PrimeIterator& operator++(); // prefix

            /**
             * @brief Overloading the ++ operator to increase the iterator by 1
             * @return PrimeIterator - the iterator before the increase
             * @throws out_of_range when trying to increment an iterator when it's at the end of the container
             * @complexity O(1)
             */
            const PrimeIterator operator++(int); // postfix

            /**
             * @brief Overloading the = operator to assign a PrimeIterator to another PrimeIterator
             * @param other - The PrimeIterator to assign to
             * @return PrimeIterator& - The assigned PrimeIterator
             */
            PrimeIterator& operator=(const PrimeIterator& other);
        };

        /**
         * @brief SideCrossIterator class - an iterator that iterates over all the numbers in the container
         * in the following order: [first, last, second, second last, third, third last, ...]
         */
        class SideCrossIterator {
            /**
             * The iterator is implemented as an index to the container
             * It's fields are:
             * The current index - is the index of the iterator in the container
             * _container - a reference to the MagicalContainer that the iterator iterates over
             * start_or_end - a boolean that indicates if the iterator is at the start or at the end of the container
             * index_from_start - the index of the iterator from the start of the container
             * index_from_end - the index of the iterator from the end of the container
             */
            MagicalContainer& _container;
            bool start_or_end;
            int index_from_start;
            int index_from_end;
            int current_index;

            /**
             * @brief A private constructor for the SideCrossIterator class
             * @param container - a reference to the MagicalContainer that the iterator iterates over
             * @param index - an index of an int in the container. the iterator will point on this index
             * @throws out_of_range if the index is out of range
             */
            SideCrossIterator(MagicalContainer& container, int index);
        public:
            /**
             * @brief A constructor for the SideCrossIterator class
             * @param container - a reference to the MagicalContainer that the iterator iterates over
             * At the beginning, the iterator will point to the first int in the container
             */
            SideCrossIterator(MagicalContainer& container);

            /**
             * @brief A copy constructor for the SideCrossIterator class
             * @param other - the SideCrossIterator to copy
             */
            SideCrossIterator(const SideCrossIterator& other);

            /**
             * For the rule of 5
             */
            ~SideCrossIterator() = default;
            SideCrossIterator(SideCrossIterator&& other) = default;
            SideCrossIterator& operator=(SideCrossIterator&& other) = delete;

            /**
             * @brief Returns an iterator to the first int in the container
             * @return SideCrossIterator - an iterator to the first int in the container
             */
            SideCrossIterator begin();

            /**
             * @brief Returns an iterator to the last int in the container
             * @return SideCrossIterator - an iterator to the last int in the container
             */
            SideCrossIterator end();

            /**
             * @brief Returns the int in the current index of the iterator
             * @return int - the int in the current index of the iterator
             */
            int operator*() const;

            /**
             * @brief Overloading the == operator to compare between two SideCrossIterators
             * @param other - The SideCrossIterator to compare to
             * @return true if the two iterators are equal, false otherwise
             */
            bool operator==(const SideCrossIterator &other) const;

            /**
             * @brief Overloading the != operator to compare between two SideCrossIterators
             * @param other - The SideCrossIterator to compare to
             * @return true if the two iterators are not equal, false otherwise
             */
            bool operator!=(const SideCrossIterator &other) const;

            /**
             * @brief Overloading the < operator to compare between two SideCrossIterators
             * @param other - The SideCrossIterator to compare to
             * @return true if the current iterator is smaller than the other iterator, false otherwise
             */
            bool operator<(const SideCrossIterator &other) const;

            /**
             * @brief Overloading the > operator to compare between two SideCrossIterators
             * @param other - The SideCrossIterator to compare to
             * @return true if the current iterator is bigger than the other iterator, false otherwise
             */
            bool operator>(const SideCrossIterator &other) const;

            /**
             * @brief Overloading the ++ operator to increase the iterator by 1
             * @return SideCrossIterator& - the iterator after the increase
             * @throws out_of_range when trying to increment an iterator when it's at the end of the container
             * @complexity O(1)
             */
            const SideCrossIterator operator++(int); // postfix

            /**
             * @brief Overloading the ++ operator to increase the iterator by 1
             * @return SideCrossIterator - the iterator before the increase
             * @throws out_of_range when trying to increment an iterator when it's at the end of the container
             * @complexity O(1)
             */
            SideCrossIterator& operator++(); // prefix

            /**
             * @brief Overloading the = operator to assign a SideCrossIterator to another SideCrossIterator
             * @param other - The SideCrossIterator to assign to
             * @return SideCrossIterator& - The assigned SideCrossIterator
             */
            SideCrossIterator& operator=(const SideCrossIterator &other);

        };

    };
}

#endif //MAGICAL_ITERATORS_MAGICALCONTAINER_H
