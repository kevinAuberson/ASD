//FORBIDDEN cout
//FORBIDDEN cerr
//FORBIDDEN printf
//FORBIDDEN puts
//FORBIDDEN putchar
//FORBIDDEN putc
#include "util.h"
#include "c.h"

int cnt = 0; // utilisez cette variable globale

void f0() noexcept {
    enter("f0");
// AJOUTEZ VOTRE CODE ICI ...

// ... FIN DE VOTRE CODE
    leave("f0");
}

C* f1() {
    enter("f1");
    C* p;
// AJOUTEZ VOTRE CODE ICI ...

// ... FIN DE VOTRE CODE
    leave("f1");
    return p;
}

C* f2() {
    enter("f2");
    C* p;
// AJOUTEZ VOTRE CODE ICI ...

// ... FIN DE VOTRE CODE
    leave("f2");
    return p;
}

void f3(C* p) noexcept {
    enter("f3");
// AJOUTEZ VOTRE CODE ICI ...

// ... FIN DE VOTRE CODE
    leave("f3");
}

void f4(C* p, size_t n) noexcept {
    enter("f4");
// AJOUTEZ VOTRE CODE ICI ...

// ... FIN DE VOTRE CODE
    leave("f4");
}

int main() {
    enter("main");
// AJOUTEZ VOTRE CODE ICI ...

// ... FIN DE VOTRE CODE
    leave("main");
}
