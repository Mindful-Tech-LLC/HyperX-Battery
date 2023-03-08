#include <iostream>
#include "cloud_flight.h"

int GET_BATTERY_PERCENTAGE();

int main()
{
	hid_device* HID_HANDLE{};

	cloud_flight::HID_DEVICE(HID_HANDLE);

	//std::cout << "Welcome to your Hyper X Cloud Flight headset!\n\nBelow you'll find useful information regarding it.\n________________________________________\n";

	//do { cloud_flight::READ_BATTERY(HID_HANDLE); } while (true);

	return 1;
}

int GET_BATTERY_PERCENTAGE()
{
	return 0;
}