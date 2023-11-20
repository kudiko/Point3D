#include "Point3D.h"

template <class T>
Point3D<T>::Point3D() noexcept : x_{0}, y_{0}, z_{0}  {}

template <class T>
Point3D<T>::Point3D(T x, T y, T z) noexcept : x_{x}, y_{y}, z_{z} {}

template <class T>
Point3D<T>::Point3D(const Point3D<T>& other) noexcept : x_{other.x_}, y_{other.y_}, z_{other.z_} {}

template <class T>
Point3D<T>& Point3D<T>::operator=(const Point3D<T>& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }
    x_ = other.x_;
    y_ = other.y_;
    z_ = other.z_;
    return *this;
}

template class Point3D<double>;
template class Point3D<float>;


template <class T>
T PointsDistance(const Point3D<T>& first, const Point3D<T>& second)
{
    return std::sqrt((first.x_ - second.x_) * (first.x_ - second.x_) +
                     (first.y_ - second.y_) * (first.y_ - second.y_) +
                     (first.z_ - second.z_) * (first.z_ - second.z_));

}
template float PointsDistance<float>(const Point3D<float>& first, const Point3D<float>& second);
template double PointsDistance<double>(const Point3D<double>& first, const Point3D<double>& second);


template <class T>
bool operator==(const Point3D<T>& lhs, const Point3D<T>& rhs)
{
    return std::abs(lhs.x_ - rhs.x_) < FLOAT_POINT_PRECISION &&
           std::abs(lhs.y_ - rhs.y_) < FLOAT_POINT_PRECISION &&
           std::abs(lhs.z_ - rhs.z_) < FLOAT_POINT_PRECISION;
}
template bool operator==<float>(const Point3D<float>& first, const Point3D<float>& second);
template bool operator==<double>(const Point3D<double>& first, const Point3D<double>& second);

template <class T>
bool operator!=(const Point3D<T>& lhs, const Point3D<T>& rhs)
{
    return !(lhs == rhs);
}
template bool operator!=<float>(const Point3D<float>& first, const Point3D<float>& second);
template bool operator!=<double>(const Point3D<double>& first, const Point3D<double>& second);

template <class T>
bool operator<(const Point3D<T>& lhs, const Point3D<T>& rhs)
{
    return std::tie(lhs.x_, lhs.y_, lhs.z_) < std::tie(rhs.x_, rhs.y_, rhs.z_);
}
template bool operator< <float>(const Point3D<float>& first, const Point3D<float>& second);
template bool operator< <double>(const Point3D<double>& first, const Point3D<double>& second);

template <class T>
Point3D<T> operator+(const Point3D<T>& lhs, const Point3D<T>& rhs)
{
    return {lhs.x_ + rhs.x_, lhs.y_ + rhs.y_, lhs.z_ + rhs.z_};
}
template Point3D<float> operator+ <float>(const Point3D<float>& first, const Point3D<float>& second);
template Point3D<double> operator+ <double>(const Point3D<double>& first, const Point3D<double>& second);

template <class T>
Point3D<T> operator-(const Point3D<T>& lhs, const Point3D<T>& rhs)
{
    return {lhs.x_ - rhs.x_, lhs.y_ - rhs.y_, lhs.z_ - rhs.z_};
}
template Point3D<float> operator- <float>(const Point3D<float>& first, const Point3D<float>& second);
template Point3D<double> operator- <double>(const Point3D<double>& first, const Point3D<double>& second);