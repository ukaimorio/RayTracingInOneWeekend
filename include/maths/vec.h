#pragma once
#include <iostream>
#include <cassert>
#include <cmath>

class vec2
{
public:
    vec2();
    ~vec2();
    vec2(float x, float y);
    vec2(const vec2 &v);
    vec2 &operator=(const vec2 &v);
    float &operator[](const size_t i);
    const float &operator[](const size_t i) const;
    vec2 operator-() const;
    vec2 operator+(const vec2 &v) const;
    vec2 operator-(const vec2 &v) const;
    vec2 operator*(const float &s) const;
    vec2 operator/(const float &s) const;
    vec2 &operator+=(const vec2 &v);
    vec2 &operator-=(const vec2 &v);
    vec2 &operator*=(const float &s);
    vec2 &operator/=(const float &s);
    float dot(const vec2 &v) const;
    float length() const;
    vec2 &normalize();
    vec2 normalized() const;
    float x, y;
};

vec2 operator*(const float &s, const vec2 &v);
std::ostream &operator<<(std::ostream &os, const vec2 &v);

class vec3
{
public:
    vec3();
    vec3(float x, float y, float z);
    vec3(const vec3 &v);
    vec3 &operator=(const vec3 &v);
    float &operator[](const size_t i);
    const float &operator[](const size_t i) const;
    vec3 operator-() const;
    vec3 operator+(const vec3 &v) const;
    vec3 operator-(const vec3 &v) const;
    vec3 operator*(const float &s) const;
    vec3 operator*(const vec3 &v) const;
    vec3 operator/(const float &s) const;
    vec3 &operator+=(const vec3 &v);
    vec3 &operator-=(const vec3 &v);
    vec3 &operator*=(const float &s);
    vec3 &operator/=(const float &s);
    float dot(const vec3 &v) const;
    vec3 cross(const vec3 &v) const;
    float length() const;
    float length_squared() const;
    bool near_zero() const;
    vec3 &normalize();
    vec3 normalized() const;
    static vec3 random();
    static vec3 random(double min, double max);
    float x, y, z;
};

// point3 is just an alias for vec3, but useful for geometric clarity in the code.
using point3 = vec3;
vec3 operator*(const float &s, const vec3 &v);
float dot(const vec3 &u, const vec3 &v);
vec3 cross(const vec3 &u, const vec3 &v);
vec3 random_in_unit_sphere();
vec3 random_in_unit_disk();
vec3 random_unit_vector();
vec3 random_on_hemisphere(const vec3 &normal);
vec3 reflect(const vec3 &v, const vec3 &n);
vec3 refract(const vec3 &uv, const vec3 &n, double etai_over_etat);
std::ostream &operator<<(std::ostream &os, const vec3 &v);

class vec4
{
public:
    vec4();
    ~vec4();
    vec4(float x, float y, float z, float w);
    vec4(const vec4 &v);
    vec4 &operator=(const vec4 &v);
    float &operator[](const size_t i);
    const float &operator[](const size_t i) const;
    vec4 operator-() const;
    vec4 operator+(const vec4 &v) const;
    vec4 operator-(const vec4 &v) const;
    vec4 operator*(const float &s) const;
    vec4 operator/(const float &s) const;
    vec4 &operator+=(const vec4 &v);
    vec4 &operator-=(const vec4 &v);
    vec4 &operator*=(const float &s);
    vec4 &operator/=(const float &s);
    float dot(const vec4 &v) const;
    float length() const;
    vec4 &normalize();
    vec4 normalized() const;
    float x, y, z, w;
};

vec4 operator*(const float &s, const vec4 &v);
std::ostream &operator<<(std::ostream &os, const vec4 &v);