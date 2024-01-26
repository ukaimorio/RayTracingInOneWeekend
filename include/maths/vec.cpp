#include <iostream>
#include <cassert>
#include <cmath>
#include "vec.h"
#include "rtweekend.h"

// vec2 implementation starts here
vec2::vec2()
{
    x = 0.0f;
    y = 0.0f;
}

vec2::~vec2() {}

vec2::vec2(float x, float y)
{
    this->x = x;
    this->y = y;
}

vec2::vec2(const vec2 &v)
{
    x = v.x;
    y = v.y;
}

vec2 &vec2::operator=(const vec2 &v)
{
    x = v.x;
    y = v.y;
    return *this;
}

float &vec2::operator[](const size_t i)
{
    assert(i < 2);
    return i == 0 ? x : y;
}

const float &vec2::operator[](const size_t i) const
{
    assert(i < 2);
    return i == 0 ? x : y;
}

vec2 vec2::operator-() const
{
    return vec2(-x, -y);
}

vec2 vec2::operator+(const vec2 &v) const
{
    return vec2(x + v.x, y + v.y);
}

vec2 vec2::operator-(const vec2 &v) const
{
    return vec2(x - v.x, y - v.y);
}

vec2 operator*(const float &s, const vec2 &v)
{
    return vec2(v.x * s, v.y * s);
}

vec2 vec2::operator*(const float &s) const
{
    return vec2(x * s, y * s);
}

vec2 vec2::operator/(const float &s) const
{
    return vec2(x / s, y / s);
}

vec2 &vec2::operator+=(const vec2 &v)
{
    x += v.x;
    y += v.y;
    return *this;
}

vec2 &vec2::operator-=(const vec2 &v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

vec2 &vec2::operator*=(const float &s)
{
    x *= s;
    y *= s;
    return *this;
}

vec2 &vec2::operator/=(const float &s)
{
    x /= s;
    y /= s;
    return *this;
}

float vec2::dot(const vec2 &v) const
{
    return x * v.x + y * v.y;
}

float vec2::length() const
{
    return std::sqrt(x * x + y * y);
}

vec2 &vec2::normalize()
{
    float l = length();
    x /= l;
    y /= l;
    return *this;
}

vec2 vec2::normalized() const
{
    float l = length();
    return vec2(x / l, y / l);
}

std::ostream &operator<<(std::ostream &os, const vec2 &v)
{
    os << "(" << v.x << "," << v.y << ")";
    return os;
}

// vec3 implementation starts here
vec3::vec3()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

vec3::vec3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

vec3::vec3(const vec3 &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}

vec3 &vec3::operator=(const vec3 &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

float &vec3::operator[](const size_t i)
{
    assert(i < 3);
    return i == 0 ? x : (i == 1 ? y : z);
}

const float &vec3::operator[](const size_t i) const
{
    assert(i < 3);
    return i == 0 ? x : (i == 1 ? y : z);
}

vec3 vec3::operator-() const
{
    return vec3(-x, -y, -z);
}

vec3 vec3::operator+(const vec3 &v) const
{
    return vec3(x + v.x, y + v.y, z + v.z);
}

vec3 vec3::operator-(const vec3 &v) const
{
    return vec3(x - v.x, y - v.y, z - v.z);
}

vec3 operator*(const float &s, const vec3 &v)
{
    return vec3(v.x * s, v.y * s, v.z * s);
}

vec3 vec3::operator*(const float &s) const
{
    return vec3(x * s, y * s, z * s);
}

vec3 vec3::operator*(const vec3 &v) const
{
    return vec3(x * v.x, y * v.y, z * v.z);
}

vec3 vec3::operator/(const float &s) const
{
    return vec3(x / s, y / s, z / s);
}

vec3 &vec3::operator+=(const vec3 &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

vec3 &vec3::operator-=(const vec3 &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

vec3 &vec3::operator*=(const float &s)
{
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

vec3 &vec3::operator/=(const float &s)
{
    x /= s;
    y /= s;
    z /= s;
    return *this;
}

float vec3::dot(const vec3 &v) const
{
    return x * v.x + y * v.y + z * v.z;
}

float dot(const vec3 &v1, const vec3 &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

vec3 vec3::cross(const vec3 &v) const
{
    return vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

vec3 cross(const vec3 &u, const vec3 &v)
{
    return vec3(u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x);
}

float vec3::length() const
{
    return std::sqrt(x * x + y * y + z * z);
}

float vec3::length_squared() const
{
    return x * x + y * y + z * z;
}

vec3 &vec3::normalize()
{
    float l = length();
    x /= l, y /= l, z /= l;
    return *this;
}

vec3 vec3::normalized() const
{
    float l = length();
    return vec3(x / l, y / l, z / l);
}

bool vec3::near_zero() const
{
    // 如果向量在所有维度上都接近于零，则返回 true。
    const auto s = 1e-8;
    return (fabs(x) < s) && (fabs(y) < s) && (fabs(z) < s);
}

vec3 vec3::random()
{
    return vec3(random_double(), random_double(), random_double());
}

vec3 vec3::random(double min, double max)
{
    return vec3(random_double(min, max), random_double(min, max), random_double(min, max));
}

vec3 random_in_unit_sphere()
{
    while (true)
    {
        auto p = vec3::random(-1, 1);
        if (p.length_squared() < 1)
            return p;
    }
}

vec3 random_in_unit_disk()
{
    while (true)
    {
        auto p = vec3(random_double(-1, 1), random_double(-1, 1), 0);
        if (p.length_squared() < 1)
            return p;
    }
}

vec3 random_unit_vector()
{
    return random_in_unit_sphere().normalize();
}

vec3 random_on_hemisphere(const vec3 &normal)
{
    vec3 on_unit_sphere = random_unit_vector();
    if (dot(on_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
        return on_unit_sphere;
    else
        return -on_unit_sphere;
}

vec3 reflect(const vec3 &v, const vec3 &n)
{
    return v - 2 * dot(v, n) * n;
}
// uv入射  n法线  etaioveretat n/n‘
vec3 refract(const vec3 &uv, const vec3 &n, double etai_over_etat)
{
    auto cos_theta = fmin(dot(-uv, n), 1.0);
    vec3 r_out_perp = etai_over_etat * (uv + cos_theta * n);
    vec3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;
    return r_out_perp + r_out_parallel;
}

std::ostream &operator<<(std::ostream &os, const vec3 &v)
{
    os << "(" << v.x << "," << v.y << "," << v.z << ")";
    return os;
}

// vec4 implementation starts here
vec4::vec4()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 0.0f;
}

vec4::~vec4() {}

vec4::vec4(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

vec4::vec4(const vec4 &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

vec4 &vec4::operator=(const vec4 &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
    return *this;
}

float &vec4::operator[](const size_t i)
{
    assert(i < 4);
    return i == 0 ? x : (i == 1 ? y : (i == 2 ? z : w));
}

const float &vec4::operator[](const size_t i) const
{
    assert(i < 4);
    return i == 0 ? x : (i == 1 ? y : (i == 2 ? z : w));
}

vec4 vec4::operator-() const
{
    return vec4(-x, -y, -z, -w);
}

vec4 vec4::operator+(const vec4 &v) const
{
    return vec4(x + v.x, y + v.y, z + v.z, w + v.w);
}

vec4 vec4::operator-(const vec4 &v) const
{
    return vec4(x - v.x, y - v.y, z - v.z, w - v.w);
}

vec4 operator*(const float &s, const vec4 &v)
{
    return vec4(v.x * s, v.y * s, v.z * s, v.w * s);
}

vec4 vec4::operator*(const float &s) const
{
    return vec4(x * s, y * s, z * s, w * s);
}

vec4 vec4::operator/(const float &s) const
{
    return vec4(x / s, y / s, z / s, w / s);
}

vec4 &vec4::operator+=(const vec4 &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

vec4 &vec4::operator-=(const vec4 &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}

vec4 &vec4::operator*=(const float &s)
{
    x *= s;
    y *= s;
    z *= s;
    w *= s;
    return *this;
}

vec4 &vec4::operator/=(const float &s)
{
    x /= s;
    y /= s;
    z /= s;
    w /= s;
    return *this;
}

float vec4::dot(const vec4 &v) const
{
    return x * v.x + y * v.y + z * v.z + w * v.w;
}

float vec4::length() const
{
    return std::sqrt(x * x + y * y + z * z + w * w);
}

vec4 &vec4::normalize()
{
    float l = length();
    x /= l;
    y /= l;
    z /= l;
    w /= l;
    return *this;
}

vec4 vec4::normalized() const
{
    float l = length();
    return vec4(x / l, y / l, z / l, w / l);
}

std::ostream &operator<<(std::ostream &os, const vec4 &v)
{
    os << "(" << v.x << "," << v.y << "," << v.z << "," << v.w << ")";
    return os;
}