#include "Biblioteca.h"
#include "Definiciones.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Sort") {
    SECTION("Order array by quick sort") {
        vector<int>v1={1,7,6,8,9,0};
        Biblioteca<int> p(v1);
        //p.quicksort(begin(v1),end(v1)-1);
        p.Quick();
        REQUIRE(p[0] == 0);
        REQUIRE(p[1]==1);
    }
}