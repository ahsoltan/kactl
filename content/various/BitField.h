/**
 * Author:
 * License: CC0
 * Source: Own work
 * Description: Pack many custom size "variables" into one using bitfields.
 * WARNING: It is not possible to take references to such "variables".
 * Overflow on such "variables" (even an unsigned ones) is implementation defined.
 */

#include<bits/stdc++.h>
using namespace std;

struct X {
    unsigned a: 10, b: 12, c: 10;
};

static_assert(sizeof(X) == 4);

int main() {
    X s;
    s.a = 0;
    s.b = 10;
    s.c = 20;
    cout << s.a << " " << s.b << " " << s.c << endl;
}