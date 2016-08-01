//
//  main.cpp
//  blacklib_application
//
//  Created by Hoàng Trung Huy on 6/17/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <iostream>
#include "BlackLib.h"

using namespace BlackLib;
using namespace std;

int main(int argc, const char * argv[]) {
        BlackUartProperties myProp( Baud9600,
                                   Baud9600,
                                   ParityNo,
                                   StopOne,
                                   Char8 );
        BlackUART sender( UART2, myProp);
        BlackUART receiver( UART4, myProp);

        if ( !sender.open(ReadWrite | NonBlock) ) {
                cout << "Failed to open UART1" << endl;
                return -1;
        }
        sender.flush(bothDirection);

        if ( !receiver.open(ReadWrite | NonBlock) ) {
                cout << "Failed to open UART1" << endl;
                return -1;
        }
        receiver.flush(bothDirection);

        const string sendString = "Sending...";

        while(1) {
                sender.write(sendString);
                cout << receiver.read() << endl;
        }

    return 0;
}
