

#include <iostream> // <...> used when is a library outside the project ; "..." used when we have the headers in the directory or subdirectory
#include "hidapi.h"
using namespace std;

int main(){
	hid_device_ *handle;
	
	struct hid_device_info *device, *current_device;
	// device = hid_enumerate(1118,673); //numbers corresponding to the xbox controller 
									  //when we write these numbers we only see the xbox device
	device = hid_enumerate(0, 0);     //when we write (0,0) we see all devices
	current_device = device;

	int i;
	i = 1;

	if (current_device != NULL){
		do{
			unsigned short IDvendor;
			IDvendor = current_device->vendor_id;
			
			unsigned short IDproduct;
			IDproduct = current_device->product_id;
			
			wchar_t *product;
			product = current_device->product_string;

			cout << "Device number: " << endl ;
			cout << i <<endl;
			cout << "The Vendor ID is: " << endl;
			cout << IDvendor <<endl;
			cout << "The Product ID is: " << endl ;
			cout << IDproduct << endl;
			wprintf_s(L"The product string is i: %s\n",product);
			current_device = current_device->next;
			i++;
		} while (current_device != NULL);
	}

	//pause to see the command window
	cout << "Press enter" << endl;
	int in;
	in = getchar();

	return 0;
}