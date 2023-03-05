#include "cloud_flight.h"
#include <iostream>
#include <Windows.h>
#include <libusb-1.0/libusb.h>

const DWORD VENDOR_ID = 0x0951;
const DWORD PRODUCT_ID = 0x1723;
const DWORD BATTERY_PACKET = 20;

// TO DO
int cloud_flight::HYPERX_DEVICE()
{
	/*libusb_device* dev;
	libusb_device_handle* dev_handle;
	libusb_context* ctx = NULL;

	UINT r = libusb_init(&ctx);

	if (r < 0)
	{
		std::cerr << "Failed to initialize!" << std::endl;
		return 1;
	}

	dev_handle = libusb_open_device_with_vid_pid(ctx, VENDOR_ID, PRODUCT_ID);
	if (dev_handle == NULL)
	{
		std::cerr << "Failed to open device!" << std::endl;
	}

	if (libusb_kernel_driver_active(dev_handle, BATTERY_PACKET) == 1)
	{
		std::cout << "Kernel Driver Active" << std::endl;
		if (libusb_detach_kernel_driver(dev_handle, BATTERY_PACKET) == 0)
		{
			std::cout << "Kernel Driver Detached" << std::endl;
		}
	}

	r = libusb_claim_interface(dev_handle, BATTERY_PACKET);
	if (r < 0)
	{
		std::cerr << "Could not claim interface!" << std::endl;
		return 1;
	}
	std::cout << "Interface claimed!" << std::endl;*/

	return 0;
}

// TO DO
int cloud_flight::CREATE_CONNECTION()
{
	return 0;
}

int cloud_flight::READ_BATTERY()
{
	WCHAR* report = new WCHAR[20];
	report[0] = 0x21;
	report[1] = 0xff;
	report[2] = 0x05;

	WCHAR* reportIn = new WCHAR[20];

	UINT chargeState = reportIn[3];
	UINT mValue = reportIn[4] != 0 ? reportIn[4] : chargeState;

	UINT percentage = CALCULATE_BATTERY_PERCENTAGE(chargeState, mValue);

	return percentage;
}

// Not using compiler extension for ranges in case x ... y:
int cloud_flight::CALCULATE_BATTERY_PERCENTAGE(int chargeState, int mValue)
{
	switch (chargeState)
	{
		case 0x0e:
		{
			if (mValue >= 0 && mValue < 90)
				return 10;
			else if (mValue >= 90 && mValue < 119)
				return 15;
			else if (mValue >= 120 && mValue < 148)
				return 20;
			else if (mValue >= 149 && mValue < 159)
				return 25;
			else if (mValue >= 160 && mValue < 169)
				return 30;
			else if (mValue >= 170 && mValue < 179)
				return 35;
			else if (mValue >= 180 && mValue < 189)
				return 40;
			else if (mValue >= 190 && mValue < 199)
				return 45;
			else if (mValue >= 200 && mValue < 209)
				return 50;
			else if (mValue >= 210 && mValue < 219)
				return 55;
			else if (mValue >= 220 && mValue < 239)
				return 60;
			else if (mValue >= 240 && mValue < 255)
				return 65;
		}
		case 0x0f:
		{
			if (mValue >= 0 && mValue < 19)
				return 70;
			else if (mValue >= 20 && mValue < 49)
				return 75;
			else if (mValue >= 50 && mValue < 69)
				return 80;
			else if (mValue >= 70 && mValue < 99)
				return 85;
			else if (mValue >= 100 && mValue < 119)
				return 90;
			else if (mValue >= 120 && mValue < 129)
				return 95;
			else if (mValue >= 130 && mValue < 255)
				return 100;
		}
	}

	return 255;
}

int cloud_flight::GET_BATTERY_PERCENTAGE()
{
	READ_BATTERY();
	return 0;
}