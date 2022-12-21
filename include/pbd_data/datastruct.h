#pragma once
#include<iostream>
#include<vector>
#include<array>
#include<memory.h>
#include<math.h>
#include<algorithm>

struct vert{
    double x, y, z;
};

struct surf_tri{
    int v[3];
};

struct tet{
    int v[4];
};