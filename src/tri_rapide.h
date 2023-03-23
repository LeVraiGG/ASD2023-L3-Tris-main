#ifndef TRI_RAPIDE
#define TRI_RAPIDE

#include <algorithm>
#include <random>
#include <chrono>

template<typename Iterator>
Iterator partition(Iterator first, Iterator last) {
    if (first == last) {
        return first;
    }
    Iterator i = first;
    Iterator j = last-1;
    while (i <= j) {
        while (*i < *last && i <= last) {
            i++;
        }

        while (j >= first && *last < *j) {
            j--;
        }

        if (i < j) {
            std::iter_swap(i, j);
        }
    }

    std::iter_swap(i, last);
    return i;
}

template<typename Iterator>
void tri_rapide(Iterator first, Iterator last) {
    unsigned seed = (unsigned) std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);
    unsigned size = unsigned(last - first);
    std::uniform_int_distribution<std::mt19937::result_type> range(0, size);

    while (std::distance(first, last) > 1) {
        //choisir le pivot de manière aléatoire
        unsigned pivotU = range(rng);
        Iterator pivot = first + pivotU;
        //permuter le pivot et last
        std::iter_swap(last, pivot);

        unsigned f = *first;
        unsigned l = *last;

        Iterator i = partition(first, last);

        if (i - first < last - i) {
            tri_rapide(first, i - 1);
            first = i + 1;
        } else {
            tri_rapide(i + 1, last);
            last = i - 1;
        }
    }

}

#endif