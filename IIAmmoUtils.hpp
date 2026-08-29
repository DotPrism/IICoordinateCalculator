#include <cmath>
#include <numbers>

#include "Math.hpp"
#include "Vec3.hpp"

class IIAmmoUtils
{
public:
	static float getDirectFireAngle(double initialVelocity, double mass, Vec3 toTarget)
	{
		double force = initialVelocity;
		double dist = toTarget.distanceTo(Vec3(0, toTarget.y, 0));
		double gravityMotionY = 0, motionY = 0, baseMotionY = toTarget.normalize().y, baseMotionYC;

		while (dist > 0)
		{
			force -= 0.01 * force;
			gravityMotionY -= 0.1 * mass;
			baseMotionYC = baseMotionY * (force / (initialVelocity));
			motionY += (baseMotionYC + gravityMotionY);
			dist -= force;
		}

		toTarget = toTarget.addVector(0, motionY - baseMotionY, 0).normalize();

		return (float)Math::toDegrees((std::atan2(toTarget.y, toTarget.distanceTo(Vec3(0, toTarget.y, 0)))));
	}

	static float calculateBallisticAngle(double distance, double height, float force, float gravity, float drag, double anglePrecision)
	{
		double bestAngle = 0;
		double bestDistance = MAX_FLOAT;
		if (gravity == 0)
			return 90 - (float)(std::atan(height / distance) * 180 / std::numbers::pi);
		/*
		 * simulate the trajectory for angles from 45 to 90 degrees,
		 * returning the angle which lands the projectile closest to the target distance
		 */
		for (double i = std::numbers::pi * anglePrecision; i < std::numbers::pi * 0.5; i += anglePrecision)
		{
			double motionX = std::cos((float)i) * force;// calculate the x component of the vector
			double motionY = std::sin((float)i) * force;// calculate the y component of the vector
			double posX = 0;
			double posY = 0;
			while (posY > height || motionY > 0)
			{
				// simulate movement, until we reach the y-level required
				motionX *= drag;
				motionY *= drag;
				motionY -= gravity;
				posX += motionX;
				posY += motionY;
			}
			double distanceToTarget = std::abs(distance - posX);
			if (distanceToTarget < bestDistance)
			{
				bestDistance = distanceToTarget;
				bestAngle = i;
			}
		}

		return 90 - (float)(bestAngle * 180 / std::numbers::pi);
	}
};