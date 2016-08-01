//============================================================================
// Name        : duc.cpp
// Author      : duc
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "BlackLib/BlackLib.h"
#include <iostream>

using namespace std;
using namespace BlackLib;

int main(int argc, const char * argv[]) {
		adcName adcPort = AIN0;
        BlackADC myADC(adcPort);

        BlackUartProperties myProp( Baud9600,
                                   Baud9600,
                                   ParityNo,
                                   StopOne,
                                   Char8 );
        BlackUART myUart4( UART4, myProp);
	if ( !myUart4.open(ReadWrite | NonBlock) ) {
		cout << "Failed to open UART1" << endl;
		return -1;
	}
	myUart4.flush(bothDirection);

        while (1) {
                myUart4.write(myADC.getValue());
        }

	myUart4.close();

        return 0;
}
