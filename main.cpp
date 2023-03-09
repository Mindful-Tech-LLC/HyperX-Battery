#include <iostream>
#include "cloud_flight.h"

int main()
{
	hid_device* HID_HANDLE{};

	std::cout << "Welcome to your Hyper X Cloud Flight headset!\n\nYour headset information:\n________________________________________\n";

	cloud_flight::HID_DEVICE(HID_HANDLE);
	
	return 1;
}