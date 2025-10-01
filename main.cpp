#include <iostream>
#include <random>
#include <vector>

using namespace std;

struct point3d
{  
    double x,y,z;

    point3d(double x=0.0, double y=0.0, double z=0.0);          ///< Конструктор по умолчанию
    void print() const;                                         ///< Выводит на экран местоположение частицs
    double getBackX() const;                                    ///< Возращает координату X
    double getBackY() const;                                    ///< Возращает координату Y
    double getBackZ() const;                                    ///< Возращает координату Z
};

//Методы point3d
point3d::point3d(double x, double y, double z) : x(x), y(y), z(z) {}

void point3d::print() const {
    std::cout << "Point(" << x << ", " << y << ", " << z << ")" << std::endl;
}

double point3d::getBackX() const { return x; }
double point3d::getBackY() const { return y; }
double point3d::getBackZ() const { return z; }


class PointGenerator {
private:
    double minX, maxX, minY, maxY, minZ, maxZ;
    mt19937 generator;
    uniform_real_distribution<double> distX, distY, distZ;

public:
    PointGenerator(double min_x, double max_x, double min_y, double max_y, double min_z, double max_z)
        : minX(min_x), maxX(max_x), minY(min_y), maxY(max_y), minZ(min_z), maxZ(max_z),
          generator(random_device{}()),
          distX(min_x, max_x), distY(min_y, max_y), distZ(min_z, max_z) {}

    point3d rnd() {
        return point3d(distX(generator), distY(generator), distZ(generator));
    }
};
