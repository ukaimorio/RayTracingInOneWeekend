#include "mat.h"

// Mat3 implementation starts here

mat3::mat3()
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            row[i][j] = 0.0f;
        }
    }
}

mat3::~mat3() {}

mat3::mat3(const mat3 &m)
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            row[i][j] = m.row[i][j];
        }
    }
}

vec3 &mat3::operator[](const size_t i)
{
    assert(i < 3);
    return row[i];
}

const vec3 &mat3::operator[](const size_t i) const
{
    assert(i < 3);
    return row[i];
}

mat3 &mat3::operator=(const mat3 &m)
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            row[i][j] = m.row[i][j];
        }
    }
    return *this;
}

mat3 mat3::operator-() const
{
    mat3 m;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            m.row[i][j] = -row[i][j];
        }
    }
    return m;
}

mat3 mat3::operator*(const mat3 &m) const
{
    mat3 r;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            for (size_t k = 0; k < 3; k++)
            {
                r.row[i][j] += row[i][k] * m.row[k][j];
            }
        }
    }
    return r;
}

mat3 mat3::operator*(const vec3 &v) const
{
    mat3 r;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            r.row[i][j] = row[i][j] * v[j];
        }
    }
    return r;
}

mat3 mat3::transpose() const
{
    mat3 r;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            r.row[i][j] = row[j][i];
        }
    }
    return r;
}

mat3 mat3::inverse() const
{
    mat3 r;
    float det = row[0][0] * (row[1][1] * row[2][2] - row[1][2] * row[2][1]) - row[0][1] * (row[1][0] * row[2][2] - row[1][2] * row[2][0]) + row[0][2] * (row[1][0] * row[2][1] - row[1][1] * row[2][0]);
    assert(det != 0.0f);
    float invdet = 1.0f / det;
    r.row[0][0] = (row[1][1] * row[2][2] - row[1][2] * row[2][1]) * invdet;
    r.row[0][1] = (row[0][2] * row[2][1] - row[0][1] * row[2][2]) * invdet;
    r.row[0][2] = (row[0][1] * row[1][2] - row[0][2] * row[1][1]) * invdet;
    r.row[1][0] = (row[1][2] * row[2][0] - row[1][0] * row[2][2]) * invdet;
    r.row[1][1] = (row[0][0] * row[2][2] - row[0][2] * row[2][0]) * invdet;
    r.row[1][2] = (row[0][2] * row[1][0] - row[0][0] * row[1][2]) * invdet;
    r.row[2][0] = (row[1][0] * row[2][1] - row[1][1] * row[2][0]) * invdet;
    r.row[2][1] = (row[0][1] * row[2][0] - row[0][0] * row[2][1]) * invdet;
    r.row[2][2] = (row[0][0] * row[1][1] - row[0][1] * row[1][0]) * invdet;
    return r;
}

mat3 mat3::inverseTranspose() const
{
    mat3 r;
    float det = row[0][0] * (row[1][1] * row[2][2] - row[1][2] * row[2][1]) - row[0][1] * (row[1][0] * row[2][2] - row[1][2] * row[2][0]) + row[0][2] * (row[1][0] * row[2][1] - row[1][1] * row[2][0]);
    assert(det != 0.0f);
    float invdet = 1.0f / det;
    r.row[0][0] = (row[1][1] * row[2][2] - row[1][2] * row[2][1]) * invdet;
    r.row[0][1] = (row[1][2] * row[2][0] - row[1][0] * row[2][2]) * invdet;
    r.row[0][2] = (row[1][0] * row[2][1] - row[1][1] * row[2][0]) * invdet;
    r.row[1][0] = (row[0][2] * row[2][1] - row[0][1] * row[2][2]) * invdet;
    r.row[1][1] = (row[0][0] * row[2][2] - row[0][2] * row[2][0]) * invdet;
    r.row[1][2] = (row[0][1] * row[2][0] - row[0][0] * row[2][1]) * invdet;
    r.row[2][0] = (row[0][1] * row[1][2] - row[0][2] * row[1][1]) * invdet;
    r.row[2][1] = (row[0][2] * row[1][0] - row[0][0] * row[1][2]) * invdet;
    r.row[2][2] = (row[0][0] * row[1][1] - row[0][1] * row[1][0]) * invdet;
    return r;
}

mat3 mat3::indentity()
{
    mat3 r;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            r[i][j] = (i == j);
        }
    }
    return r;
}

std::ostream &operator<<(std::ostream &os, const mat3 &m)
{
    return os << m[0] << std::endl
              << m[1] << std::endl
              << m[2] << std::endl;
}

// Mat4 implementation starts here

mat4::mat4()
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            row[i][j] = 0.0f;
        }
    }
}

mat4::~mat4() {}

mat4::mat4(const mat4 &m)
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            row[i][j] = m.row[i][j];
        }
    }
}

vec4 &mat4::operator[](const size_t i)
{
    assert(i < 4);
    return row[i];
}

const vec4 &mat4::operator[](const size_t i) const
{
    assert(i < 4);
    return row[i];
}

mat4 &mat4::operator=(const mat4 &m)
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            row[i][j] = m.row[i][j];
        }
    }
    return *this;
}

mat4 mat4::operator-() const
{
    mat4 m;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            m.row[i][j] = -row[i][j];
        }
    }
    return m;
}

mat4 mat4::operator*(const mat4 &m) const
{
    mat4 r;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            for (size_t k = 0; k < 4; k++)
            {
                r.row[i][j] += row[i][k] * m.row[k][j];
            }
        }
    }
    return r;
}

mat4 mat4::operator*(const vec4 &v) const
{
    mat4 r;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            r.row[i][j] = row[i][j] * v[j];
        }
    }
    return r;
}

mat4 mat4::transpose() const
{
    mat4 r;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            r.row[i][j] = row[j][i];
        }
    }
    return r;
}
