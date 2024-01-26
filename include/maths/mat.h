#pragma once

#include <cmath>
#include <cassert>
#include <iostream>
#include "vec.h"

class mat3
{
public:
    mat3();
    ~mat3();
    mat3(const mat3 &m);
    vec3 &operator[](const size_t i);
    const vec3 &operator[](const size_t i) const;
    mat3 &operator=(const mat3 &m);
    mat3 operator-() const;
    mat3 operator*(const mat3 &m) const;
    mat3 operator*(const vec3 &v) const;

    mat3 transpose() const;
    mat3 inverse() const;
    mat3 inverseTranspose() const;
    mat3 indentity();

    vec3 row[3];
};

std::ostream &operator<<(std::ostream &os, const mat3 &m);

class mat4
{
public:
    mat4();
    ~mat4();
    mat4(const mat4 &m);
    vec4 &operator[](const size_t i);
    const vec4 &operator[](const size_t i) const;
    mat4 &operator=(const mat4 &m);
    mat4 operator-() const;
    mat4 operator*(const mat4 &m) const;
    mat4 operator*(const vec4 &v) const;

    mat4 transpose() const;
    mat4 inverse() const;
    mat4 inverseTranspose() const;
    mat4 indentity();

    vec4 row[4];
};

std::ostream &operator<<(std::ostream &os, const mat3 &m);