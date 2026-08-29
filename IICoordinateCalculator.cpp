#include <print>
#include <iostream>
#include <cmath>
#include <numbers>

#include "IIAmmoUtils.hpp"

int main()
{
	while (true)
	{
		int howitzerX, howitzerY, howitzerZ;
		int targetX, targetY, targetZ;
		float mass;
		double force;

		std::print("Welcome to the Immersive Intelligence Coordinate Calculator!\n"
			"This nifty tool will help with calculating the absolute coordinates needed for the ballistic computer!\n"
			"Enter Artillery Howitzer bottom center coordinates:\n"
			"DO NOT USE COMMAS! Format: X Y Z\n");
		if (!(std::cin >> howitzerX >> howitzerY >> howitzerZ))
		{
			std::print("Invalid coordinates.\n");
			return 1;
		}
		std::print("Enter Target coordinates:\n"
			"DO NOT USE COMMAS! Format: X Y Z\n");
		if (!(std::cin >> targetX >> targetY >> targetZ))
		{
			std::print("Invalid coordinates.\n");
			return 1;
		}

		std::print("Enter Force\n");
		if (!(std::cin >> force))
		{
			std::print("Invalid force.\n");
			return 1;
		}

		std::print("Enter Mass\n");
		if (!(std::cin >> mass))
		{
			std::print("Invalid mass.\n");
			return 1;
		}

		int relativeX = targetX - howitzerX;
		int relativeY = targetY - howitzerY;
		int relativeZ = targetZ - howitzerZ;

		std::print("Absolute coordinates:\n");
		std::print("X: {}, Y: {}, Z: {}\n", relativeX, relativeY, relativeZ);

		float distance = (float)Vec3(0, 0, 0).distanceTo(Vec3(relativeX, 0, relativeZ));

		float drag = 0.01;
		float gravity = 0.1 * mass;

		float yaw;
		if (relativeX < 0 && relativeZ >= 0)
			yaw = (float)(std::atan(std::abs((double)relativeX / (double)relativeX)) / std::numbers::pi * 180);
		else if (relativeX <= 0 && relativeZ <= 0)
			yaw = (float)(std::atan(std::abs((double)relativeZ / (double)relativeX)) / std::numbers::pi * 180) + 90;
		else if (relativeZ < 0)
			yaw = (float)(std::atan(std::abs((double)relativeX / (double)relativeZ)) / std::numbers::pi * 180) + 180;
		else
			yaw = (float)(std::atan(std::abs((double)relativeZ / (double)relativeX)) / std::numbers::pi * 180) + 270;

		float pitch;

		//direct
		bool direct;

		if (!(std::cin >> direct))
		{
			std::print("Invalid input. Please enter 1 for direct fire or 0 for ballistic fire.\n");
			return 1;
		}
		else if (direct == true)
			pitch = 90 - IIAmmoUtils::getDirectFireAngle((float)force, mass, Vec3(relativeX, relativeY, relativeZ));
		else //ballistic
			pitch = IIAmmoUtils::calculateBallisticAngle(distance, relativeY, (float)force, gravity, drag, 0.002);

		std::print("Yaw: {}, Pitch: {}\n", yaw, pitch);

		std::print("Want to calculate another coordinate? (Y/N)\n");
		char choice;
		std::cin >> choice;

		switch (choice)
		{
		case 'Y':
		case 'y':
			continue;
		case 'N':
		case 'n':
			std::print("Thank you for using the Immersive Intelligence Coordinate Calculator!\n");
			return 0;
		default:
			std::print("Invalid input. Exiting program.\n");
			return 1;
		}
	}
}
