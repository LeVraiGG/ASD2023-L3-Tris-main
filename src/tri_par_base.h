#ifndef TRI_PAR_BASE
#define TRI_PAR_BASE

#include <iterator>
#include <type_traits>
#include "some_bits.h"

template<typename Iterator, typename Fn>
void tri_comptage(Iterator first, Iterator last, Iterator output_first, Fn index_fn, size_t N)
{

    // a compléter

}

template<typename Iterator, size_t NBITS>
void tri_par_base(Iterator first, Iterator last)
{
    using T = typename Iterator::value_type;
    static_assert(std::is_unsigned<T>::value);

    // a compléter

}

#endif