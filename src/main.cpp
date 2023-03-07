#include <iostream>
#include "cloud_flight.h"

int GET_BATTERY_PERCENTAGE();

int main()
{
	cloud_flight::HID_DEVICE();

	std::cout << "Welcome to your Hyper X Cloud Flight headset!\n\nBelow you'll find useful information regarding it.\n________________________________________\n";

	do { READ_BATTERY(HID_HANDLE); } while (true);

	return 1;
}

int GET_BATTERY_PERCENTAGE()
{
	return 0;
}