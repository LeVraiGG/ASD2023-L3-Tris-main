#include <iostream>
#include <limits>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include "some_bits.h"
#include "tri_rapide.h"

using namespace std;
using ui = unsigned int;

void testTri() {
    vector<int> vRef(100);
    iota(vRef.begin(), vRef.end(), 1);

    vector<int> vRapide = vRef;

    unsigned seed = (unsigned) std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rng(seed);


    shuffle(vRapide.begin(), vRapide.end(), rng);

    auto test = vRapide.end()-1;
    unsigned t = vRapide.end()-vRapide.begin();

    tri_rapide(vRapide.begin(), vRapide.end()-1);

    assert(vRapide == vRef);
}

int main() {

    testTri();

    ui n; cin >> n;

    for(unsigned nbits : { 1u, 2u, 4u, 8u, 16u }) {
        cout << nbits << " : ";
        for (unsigned i = 0; i < numeric_limits<ui>::digits / nbits ; ++i ) {
            auto fn = SomeBits<unsigned long long>(nbits, i);
            cout << fn(n) << " ";
        }
        cout << endl;
    }
}