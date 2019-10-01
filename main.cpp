/*#define CATCH_CONFIG_MAIN
#include "catch.hpp"*/
#include "Definiciones.h"
#include "Biblioteca.h"
#include "Archivo.h"

int main() {
    vector<int> a;
    a.push_back(2);
    a.push_back(4);
    a.push_back(1);
    a.push_back(13);
    a.push_back(2);
    a.push_back(6);
    a.push_back(5);

    Biblioteca<int> b(a);
    b.Merge();
    b.print();

    vector<string> q;
    q.push_back("Hola");
    q.push_back("Alo");
    q.push_back("Barrios");
    q.push_back("Silva");
    q.push_back("Hello");
    q.push_back("Zorro");
    q.push_back("Supe");

    cout << endl;
    Biblioteca<string> b_1(q);
    b_1.Shell();
    b_1.print();

    vector<int> c;
    c.push_back(3);
    c.push_back(12);
    c.push_back(13);
    c.push_back(15);
    c.push_back(3);
    c.push_back(45);
    c.push_back(11);

    Biblioteca<int> b_2(c);
    b_2.Quick();
    b_2.print();

    vector<char> w;
    w.push_back('A');
    w.push_back('a');
    w.push_back('D');
    w.push_back('C');
    w.push_back('d');
    w.push_back('b');
    w.push_back('M');

    Biblioteca<char> b_3(w);
    b_3.Heap();
    b_3.print();

    return 0;
}