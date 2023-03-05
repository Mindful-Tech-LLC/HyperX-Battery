#include <iostream>
#include <Windows.h>
#include <libusb-1.0/libusb.h>

#pragma once
class cloud_flight
{
public:
	static int HID_DEVICE();
	static int CREATE_CONNECTION(libusb_context *LIB_CONTEXT, libusb_device *DEVICE, libusb_device_handle *DEVICE_HANDLE, UINT VENDOR, UINT PRODUCT);
	static int READ_BATTERY();
	static int CALCULATE_BATTERY_PERCENTAGE(int chargeState, int mValue);
};