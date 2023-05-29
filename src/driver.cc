#include <iostream>

#include "dna_strand.hpp"

int main() {
    DNAstrand* Dna = new DNAstrand(); /*
    char one = new Node('A');
    char two = new Node('E');
    char three = new Node('I');
    char four = new Node('A');
    Node* five = new Node('E'); */
    const int size = 5;
    char hold[size] = {'a','a','a','a','t'};
    Dna->AddTest(hold,size);
    char pattern[4] = {'a','a','t','\0'};
    char replace[3] = {'t','g','a'};
    DNAstrand* splice = new DNAstrand();
    splice->AddTest(replace,3);
    Dna->SpliceIn(pattern, *splice);
    delete Dna;
}