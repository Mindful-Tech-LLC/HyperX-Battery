#include "cloud_flight.h"

const int VENDOR_ID = 0x0951; // 2385
const int PRODUCT_ID = 0x1723; // 5923
// const int CHARGING_PRODUCT_ID = 0x1725; // 5925

int cloud_flight::HID_DEVICE()
{
	int HID;
	hid_device* HID_HANDLE{};

	HID = hid_init();

	if (!(HID_HANDLE = hid_open(VENDOR_ID, PRODUCT_ID, NULL)))
	{
		std::cerr << "Error opening device, checking charging..." << std::endl;
	}

	std::cout << "Welcome to your Hyper X Cloud Flight headset!\n\nBelow you'll find useful information regarding it.\n________________________________________\n";

	do { READ_BATTERY(HID_HANDLE); } while (true);

	EXIT();
}

int cloud_flight::READ_BATTERY(hid_device* HID_HANDLE)
{
	int j;
	unsigned char report[20];
	report[0] = 0x21;
	report[1] = 0xff;
	report[2] = 0x05;

	hid_write(HID_HANDLE, report, 20);
	hid_read(HID_HANDLE, report, 20);

#ifdef DEBUG
	for (int j = 0; j < 20; j++)
	{
		std::cout << int((unsigned char)report[j]) << " | ";
	}
#endif

	int CHARGE_STATE = report[3];
	int M_VALUE = report[4] != 0 ? report[4] : CHARGE_STATE;

	int BATTERY_PERCENTAGE = CALCULATE_BATTERY_PERCENTAGE(CHARGE_STATE, M_VALUE);

	std::cout << '\r' << "Battery: " << BATTERY_PERCENTAGE << "%";

	return BATTERY_PERCENTAGE;
}

// Not using compiler extension for ranges in case x ... y:
int cloud_flight::CALCULATE_BATTERY_PERCENTAGE(int CHARGE_STATE, int M_VALUE)
{
	switch (CHARGE_STATE)
	{
		case 0x10:
			if (M_VALUE >= 0 && M_VALUE < 90)
				return 10;
			else if (M_VALUE >= 90 && M_VALUE < 119)
				return 15;
			else if (M_VALUE >= 120 && M_VALUE < 148)
				return 20;
			else if (M_VALUE >= 149 && M_VALUE < 159)
				return 25;
			else if (M_VALUE >= 160 && M_VALUE < 169)
				return 30;
			else if (M_VALUE >= 170 && M_VALUE < 179)
				return 35;
			else if (M_VALUE >= 180 && M_VALUE < 189)
				return 40;
			else if (M_VALUE >= 190 && M_VALUE < 199)
				return 45;
			else if (M_VALUE >= 200 && M_VALUE < 209)
				return 50;
			else if (M_VALUE >= 210 && M_VALUE < 219)
				return 55;
			else if (M_VALUE >= 220 && M_VALUE < 239)
				return 60;
			else if (M_VALUE >= 240 && M_VALUE < 255)
				return 65;

		case 0xf:
			if (M_VALUE >= 0 && M_VALUE < 19)
				return 70;
			else if (M_VALUE >= 20 && M_VALUE < 49)
				return 75;
			else if (M_VALUE >= 50 && M_VALUE < 69)
				return 80;
			else if (M_VALUE >= 70 && M_VALUE < 99)
				return 85;
			else if (M_VALUE >= 100 && M_VALUE < 119)
				return 90;
			else if (M_VALUE >= 120 && M_VALUE < 129)
				return 95;
			else if (M_VALUE >= 130 && M_VALUE < 255)
				return 100;

		case 0xe:
			if (M_VALUE < 250 && M_VALUE > 240)
				return 65;
			else if (M_VALUE < 240 && M_VALUE >= 220)
				return 60;
			else if (M_VALUE < 220 && M_VALUE >= 208)
				return 55;
			else if (M_VALUE < 208 && M_VALUE >= 200)
				return 50;
			else if (M_VALUE < 200 && M_VALUE >= 190)
				return 45;
			else if (M_VALUE < 190 && M_VALUE >= 180)
				return 40;
			else if (M_VALUE < 179 && M_VALUE >= 169)
				return 35;
			else if (M_VALUE < 169 && M_VALUE >= 159)
				return 30;
			else if (M_VALUE < 159 && M_VALUE >= 148)
				return 25;
			else if (M_VALUE < 148 && M_VALUE >= 119)
				return 20;
			else if (M_VALUE < 119 && M_VALUE >= 90)
				return 15;
			else if (M_VALUE < 90)
				return 10;
			else if (M_VALUE < 69)
				return 5;
	}

	return 255;
}

int cloud_flight::EXIT()
{
	hid_exit();
	return 0;
}


// Other things to check for in a HyperX Cloud Flight headset
// 
// 
//if (report[0] == 0x64)
//{
//	if (report[1] == 0x01)
//	{
//		std::cout << "Power on!";
//	}
//	else if (report[1] == 0x03)
//	{
//		std::cout << "Power off :(";
//	}
//}
//if (report[0] == 0x65)
//{
//	if (report[1] == 0x04)
//	{
//		std::cout << "Muted!";
//	}
//	else {
//		std::cout << "Not Muted!";
//	}
//}
//
//