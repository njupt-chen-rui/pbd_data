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

struct vec3{
    double x, y, z;
    vec3(double x, double y, double z): x{x}, y{y}, z{z} {}
};

struct surf_tri{
    int v[3];
};

struct tet{
    int v[4];
};