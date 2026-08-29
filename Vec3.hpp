#include <cmath>

class Vec3
{
public:
	double x, y, z;

	Vec3(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ) {}
	Vec3(double in) : x(in), y(in), z(in) {}

	double distanceTo(const Vec3& vec) const
	{
		double d0 = vec.x - x;
		double d1 = vec.y - y;
		double d2 = vec.z - z;
		return std::sqrt(d0 * d0 + d1 * d1 + d2 * d2);
	}

	Vec3 addVector(double inX, double inY, double inZ)
	{
		return Vec3(inX + x, inY + y, inZ + z);
	}

	Vec3 add(Vec3 vec)
	{
		return addVector(vec.x, vec.y, vec.z);
	}

	Vec3 subtract(double inX, double inY, double inZ)
	{
		return addVector(-inX, -inY, -inZ);
	}

	Vec3 normalize()
	{
		double d0 = (double)std::sqrt(x * x + y * y + z * z);
		return d0 < static_cast<double>(1.0E-4) ? Vec3(0) : Vec3(x / d0, y / d0, z / d0);
	}
};