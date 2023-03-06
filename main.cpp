#include <iostream>
#include "cloud_flight.h"

int GET_BATTERY_PERCENTAGE();

int main()
{
	cloud_flight::HID_DEVICE();
	//std::cout << cloud_flight::READ_BATTERY();
}

int GET_BATTERY_PERCENTAGE()
{
	return 0;
}