#include <iostream>
#include <string.h>
using namespace std;

class node
{
    public:
        int
        noMhs;
        node *next;
};

class list{
    node *START;

    public:
    list(){
        START = NULL;
    }
};