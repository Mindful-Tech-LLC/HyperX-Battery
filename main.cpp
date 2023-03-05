#include <iostream>
#include <Windows.h>
#include <hidsdi.h>

const DWORD VENDOR_ID = 0x0951;
const DWORD PRODUCT_ID = 0x1723;
const DWORD PRODUCT_IDS[] = { 0x1723, 0x16c4 };

int HYPERX_DEVICE();

enum CloudFlight {
	Battery = 0,
	Muted = 0,
	PowerT = 1
};

int main()
{

}

int HYPERX_DEVICE()
{
	return 1;
}