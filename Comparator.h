#ifndef COMP_H
#define COMP_H

#include <bits/stdc++.h>

using namespace std;

class Compare
{
public:
    bool operator()(const Record &r1, const Record &r2)
    {
        float v1, v2;
        v1 = r1.getNormal();
        v2 = r2.getNormal();
        return  v1 < v2;
    }
};

#endif
