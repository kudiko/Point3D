#include <iostream>
#include <cmath>


template <class T>
struct Point3D {
    Point3D() noexcept : x_{0}, y_{0}, z_{0}  {}

    Point3D(T x, T y, T z) noexcept : x_{x}, y_{y}, z_{z} {}

    Point3D(const Point3D<T>& other) noexcept : x_{other.x_}, y_{other.y_}, z_{other.z_} {}

    Point3D& operator=(const Point3D<T>& other) noexcept {
        if (this == &other) {
            return *this;
        }
        x_ = other.x_;
        y_ = other.y_;
        z_ = other.z_;
        return *this;

    }
    ~Point3D() = default;


    T x_;
    T y_;
    T z_;
};

template <class T>
T PointsDistance(const Point3D<T>& first, const Point3D<T>& second)
{
    return std::sqrt((first.x_ - second.x_) * (first.x_ - second.x_) +
                     (first.y_ - second.y_) * (first.y_ - second.y_) +
                     (first.z_ - second.z_) * (first.z_ - second.z_));

}



int main() {
    Point3D<double> zero;

    Point3D<double> unit_vec{1,0,0};

    std::cout << PointsDistance(zero, unit_vec) << std::endl;

    auto& [x,y,z] = unit_vec;

    y = 1;
    z = 1;
    std::cout << PointsDistance(zero, unit_vec) << std::endl;

    return 0;
}
