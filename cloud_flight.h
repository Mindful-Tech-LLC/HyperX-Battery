#include <iostream>
#include <hidapi/hidapi.h>

#pragma comment(lib, "hidapi.lib")


#pragma once
class cloud_flight
{
public:
	static int HID_DEVICE(hid_device* HID_HANDLE);
	static int READ_BATTERY(hid_device* HID_HANDLE);
	static int READ_MUTE(hid_device* HID_HANDLE);
	static int CALCULATE_BATTERY_PERCENTAGE(int CHARGE_STATE, int M_VALUE);
	static int EXIT();
};