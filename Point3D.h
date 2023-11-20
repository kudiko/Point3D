#pragma once
#include <cmath>
#include <type_traits>
#include <tuple>

constexpr inline double FLOAT_POINT_PRECISION = 1e-6;

template <class T = double>
struct Point3D {
    static_assert(std::is_floating_point<T>::value);
    Point3D() noexcept;

    Point3D(T x, T y, T z) noexcept;

    Point3D(const Point3D<T>& other) noexcept;

    Point3D& operator=(const Point3D<T>& other) noexcept;
    ~Point3D() = default;


    T x_;
    T y_;
    T z_;
};

template <class T>
T PointsDistance(const Point3D<T>& first, const Point3D<T>& second);

template <class T>
bool operator==(const Point3D<T>& lhs, const Point3D<T>& rhs);

template <class T>
bool operator!=(const Point3D<T>& lhs, const Point3D<T>& rhs);

template <class T>
bool operator<(const Point3D<T>& lhs, const Point3D<T>& rhs);

template <class T>
Point3D<T> operator+(const Point3D<T>& lhs, const Point3D<T>& rhs);

template <class T>
Point3D<T> operator-(const Point3D<T>& lhs, const Point3D<T>& rhs);




