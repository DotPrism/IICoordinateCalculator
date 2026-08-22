#include <print>
#include <iostream>

int main()
{
	while (true)
	{
		int howitzerX, howitzerY, howitzerZ;
		int targetX, targetY, targetZ;

		std::print("Welcome to the Immersive Intelligence Coordinate Calculator!\n");
		std::print("This nifty tool will help with calculating the absolute coordinates needed for the ballistic computer!\n");
		std::print("Enter Artillery Howitzer bottom center coordinates:\n");
		std::print("DO NOT USE COMMAS! Format: X Y Z\n");
		std::cin >> howitzerX >> howitzerY >> howitzerZ;
		std::print("Enter Target coordinates:\n");
		std::print("DO NOT USE COMMAS! Format: X Y Z\n");
		std::cin >> targetX >> targetY >> targetZ;

		int relativeX = targetX - howitzerX;
		int relativeY = targetY - howitzerY;
		int relativeZ = targetZ - howitzerZ;

		std::print("Absolute coordinates:\n");
		std::print("X: {}, Y: {}, Z: {}\n", relativeX, relativeY, relativeZ);

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

	return 0;
}
