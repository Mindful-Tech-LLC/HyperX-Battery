#pragma once
class cloud_flight
{
public:
	static int HYPERX_DEVICE();
	static int CREATE_CONNECTION();
	static int READ_BATTERY();
	static int CALCULATE_BATTERY_PERCENTAGE(int chargeState, int mValue);

	static int GET_BATTERY_PERCENTAGE();
};