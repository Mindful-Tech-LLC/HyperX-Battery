#include <iostream>
#include <Windows.h>
#include <hidapi/hidapi.h>

#pragma comment(lib, "hidapi.lib")


#pragma once
class cloud_flight
{
public:
	static int HID_DEVICE();
	static int READ_BATTERY(hid_device* dev);
	static int CALCULATE_BATTERY_PERCENTAGE(int CHARGE_STATE, int M_VALUE);
	static int EXIT();
};