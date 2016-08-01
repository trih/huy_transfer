//============================================================================
// Name        : interface_RFID_sensor.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : interface_sensor_RFID.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <signal.h>
#include "BlackDef.h"
#include "BlackErr.h"
#include "BlackGPIO.h"
#include "BlackUART.h"
#include "BlackSPI.h"
using namespace std;
using namespace BlackLib;
int vall1,vall2,vall3,vall4,vall5;
void gpio_config();
//void uart_config();
void uart_config(string testMessage);
void detect_deviation_left_righ_straight();
void ECHO_command();
void IDN_command();
void setprotocol_command();
void Inventory_Command();
void lift_pallet();
void turn_right();
//void sig_handler_IO(int signum);
//int tagID_handling();
//void uart5_config();
int Hex2Asc(char *Dest,unsigned char *Src,int SrcLen);
uint8_t NFCReady = 0;
int main(void)
{
	/*BlackLib::BlackGPIO set1(BlackLib::GPIO_49, BlackLib::output, BlackLib::SecureMode);

	sleep(1);

	set1.setValue(BlackLib::high);
	usleep(500);

	set1.setValue(BlackLib::low);
	usleep(100);

	set1.setValue(BlackLib::high);
	sleep(1);
	while(1)
		{
			if(NFCReady == 0)
			{
				ECHO_command();
				sleep(1);
				IDN_command();
				sleep(1);
				setprotocol_command();
				sleep(1);
			}
			else
			{
				Inventory_Command();
				sleep(1);
			}
		}*/
		while(1)
		{
			gpio_config();
		}
}
void gpio_config()
{
	BlackLib::BlackGPIO val1(BlackLib::GPIO_67, BlackLib::input, BlackLib::SecureMode);
	BlackLib::BlackGPIO val2(BlackLib::GPIO_68, BlackLib::input, BlackLib::SecureMode);
	BlackLib::BlackGPIO val3(BlackLib::GPIO_44, BlackLib::input, BlackLib::SecureMode);
	BlackLib::BlackGPIO val4(BlackLib::GPIO_26, BlackLib::input, BlackLib::SecureMode);
	BlackLib::BlackGPIO val5(BlackLib::GPIO_46, BlackLib::input, BlackLib::SecureMode);
	BlackLib::BlackGPIO set1(BlackLib::GPIO_49, BlackLib::output, BlackLib::SecureMode);
	vall1=val1.getNumericValue();
	vall2=val2.getNumericValue();
	vall3=val3.getNumericValue();
	vall4=val4.getNumericValue();
	vall5=val5.getNumericValue();
	cout << "\r\n val1 : "<< vall1 << " | val2 : " << vall2 << " | val3 : " << vall3 <<" | val4 : " << vall4 << "  | val5 : " << vall5;
	cout<<"\r\n"<<endl;
	detect_deviation_left_righ_straight();

}
void detect_deviation_left_righ_straight()
{
	//************************* Detect go to ****************************************//
	if(vall1 == 0 && vall2 == 1 && vall3 == 1 && vall4 == 1 && vall5 == 0)
	{
		cout<<"\n go to straight" << endl;
		string testMessage = "go to straight\r\n";
		uart_config(testMessage);
	}
	//************************* Detect deviation one  righ *************************//
	else if((vall1 == 0 && vall2 == 0 && vall3 == 1 && vall4 == 1 && vall5== 0) || (vall1 == 0 && vall2 == 0 && vall3 == 1 && vall4 == 1 && vall5== 1))
	{
		cout<<"\n deviation one righ" << endl;
		string testMessage = "deviation one righ\r\n";
		uart_config(testMessage);
	}
	//************************* deviation one  righ & deviation one center *************************//
	else if(vall1 == 0 && vall2 == 0 && vall3 == 0 && vall4 ==1 && vall5 == 1)
	{
		cout<<"\n deviation one  righ & deviation one center " << endl;
		string testMessage = "deviation one  righ & deviation one center\r\n";
		uart_config(testMessage);
	}
	//************************* deviation one righ & deviation one center & deviation one left *************************//
	else if(vall1 == 0 && vall2 == 0 && vall3 == 0 && vall4 ==0 && vall5 == 1)
	{
		cout<<"\n deviation one righ & deviation one center & deviation one left_the right " << endl;
		string testMessage = "deviation one  righ & deviation one center  & deviation one left_the right\r\n";
		uart_config(testMessage);
	}
	//************************* deviation one  righ & deviation one center & deviation one left & deviation two left *************************//
	else if(vall1 == 0 && vall2 == 0 && vall3 == 0 && vall4 ==0 && vall5 == 1)
	{
		cout<<"\n deviation one righ & deviation one center_the right & deviation one left_the right & deviation two left_the right" << endl;
		string testMessage ="deviation one righ & deviation one center_the right & deviation one left_the right & deviation two left_the right\r\n";
		uart_config(testMessage);
	}
	//************************* Detect deviation one left *************************//
	else if((vall1 == 0 && vall2 == 1 && vall3 == 1 && vall4 == 0 && vall5 == 0) || (vall1 == 1 && vall2 == 1 && vall3 == 1 && vall4 == 0 && vall5 == 0))
	{
		cout<<"\n deviation one left" << endl;
		string testMessage ="deviation one left\r\n";
		uart_config(testMessage);
	}
	//************************* deviation one  left & deviation one center_the left *************************//
	else if(vall1 == 1 && vall2 == 1 && vall3 == 0 && vall4 == 0 && vall5 == 0)
	{
		cout<<"\n deviation one left & deviation one center_the left " << endl;
		string testMessage ="deviation one left & deviation one center_the left \r\n";
		uart_config(testMessage);
	}
	//************************* deviation one  righ & deviation one center & deviation one left & deviation two left *************************//
	else if(vall1 == 1 && vall2 == 0 && vall3 == 0 && vall4 == 0 && vall5 == 0)
	{
		cout<<"\n deviation one left & deviation one center_the left & deviation one righ_the left & deviation two righ_the left" << endl;
		string testMessage ="deviation one left & deviation one center_the left & deviation one righ_the left & deviation two righ_the left \r\n";
		uart_config(testMessage);
	}
	//************************* deviation turn 90 *************************//
	else if(vall1 == 1 && vall2 == 1 && vall3 == 1 && vall4 == 1 && vall5 == 1)
	{
		cout<<"\n prepare turn 90" << endl;
		string testMessage ="prepare turn 90 \r\n";
		uart_config(testMessage);
	}
	//************************* deviation half righ *************************//
	else if(vall1 ==1 && vall2 == 1 && vall3 == 1 && vall4 == 1 && vall5 == 0)
	{
		cout<<"\n deviation half righ" << endl;
		string testMessage ="deviation half righ \r\n";
		uart_config(testMessage);
	}
	//************************* deviation half righ *************************//
	else if(vall1 ==0 && vall2 == 1 && vall3 == 1 && vall4 == 1 && vall5 == 1)
	{
		cout<<"\n deviation half left" << endl;
		string testMessage ="deviation half left \r\n";
		uart_config(testMessage);
	}
	else if(vall1 == 0 && vall2 == 0 && vall3 == 0 && vall4 == 0 && vall5 == 0)
	{
		cout<<"\n Stop" << endl;
	}
	else
	{
		return;
	}
}
void uart_config(string testMessage)
{
	BlackLib::BlackUART uartDemo( BlackLib::UART1,BlackLib::Baud9600,BlackLib::ParityNo,BlackLib::StopOne,BlackLib::Char8);
	uartDemo.open( ReadWrite | NonBlock);
	//uartDemo.setBaudRate( BlackLib::Baud57600,BlackLib::bothDirection );
	//string testMessage = "This is uart test message.\r\n";
    uartDemo.transfer(testMessage,0);
}
void ECHO_command()
{
	//BlackLib::BlackSPI  mySpi(BlackLib::SPI1_0,8,BlackLib::SpiMode0,500000);
	BlackLib::BlackSPI  mySpi(BlackLib::SPI1_0,8,BlackLib::SpiMode0,500000);
	bool isOpened = mySpi.open( BlackLib::ReadWrite | BlackLib::NonBlock);
	if( !isOpened )
	{

		std::cout << "SPI DEVICE CAN\'T OPEN.;" << std::endl;
		exit(1);
	}
	else
	{
		cout<<"  \n OPEN spi: " <<endl;
	}
	sleep(1);
	uint8_t write [4] = {0x00,0x55,0x00};   //send ECHO
	uint8_t write0 = 0x03;                 //Poll the CR95HF
	uint8_t write1 [3] = {0x02,0x00,0x00};//Read data from the CR95HF
	uint8_t read[50];
	mySpi.transfer(write,read,sizeof(write),5000); //write ECHO
	while (read[0] != 8)                                      //wait bit 3 ( EX: '0000 1000')
		{
			read[0] = mySpi.transfer(write0,5000);        //write poll 0x03
			printf("resceive data = %02X\r\n",read[0]);
			if(read[0] & 0x08)
			{
				printf("exit \r\n");
				break;
			}

		}
	//read[0]=mySpi.transfer(write2,5000);
	//read[1]=mySpi.transfer(write2,5000);
	mySpi.transfer(write1,read,sizeof(write1),5000); //write command read data
	printf("resceive data_after_readdata = %02x\r\n",read[1]);    //print data
	sleep(1);
}
void IDN_command()
{
	BlackLib::BlackSPI  mySpi(BlackLib::SPI1_0,8,BlackLib::SpiMode0,500000);
	bool isOpened = mySpi.open( BlackLib::ReadWrite | BlackLib::NonBlock);
	if( !isOpened )
	{
		std::cout << "SPI DEVICE CAN\'T OPEN.;" << std::endl;
		exit(1);
	}
	else
	{
		cout<<"  \n OPEN spi: " <<endl;
	}
	sleep(1);
	uint8_t write[3] = {0x00,0x01,0x00};
	uint8_t write0 =0x03;
	uint8_t write1[50] = {0x02};
	uint8_t read[200];
	memset(read,0,sizeof(read));
	mySpi.transfer(write,read,sizeof(write),5000);
	while (read[0] != 8)                                      //wait bit 3 ( EX: '0000 1000'
		{
			read[0] = mySpi.transfer(write0,5000);
			read[0] = read[0] & 0x08;//write poll 0x03
			printf("resceive data_IDN = %02X\r\n",read[0]);
			if(read[0] & 0x08)
			{
				printf("exit protocol \r\n");
				break;
			}

		}
	mySpi.transfer(write1,read,sizeof(write1),5000);
	if(read[1] == 0x00 && read[2] == 0x0F)
	{
		printf("IDN :%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X \r\n",read[1],read[2],read[3],read[4],read[5],read[6],read[7],
																								read[8],read[9],read[10],read[11],read[12],read[13],read[14]);

	}
	else
	{
		printf("FAIL");
	}
}
void setprotocol_command()
{
	BlackLib::BlackSPI  mySpi(BlackLib::SPI1_0,8,BlackLib::SpiMode0,500000);
	bool isOpened = mySpi.open( BlackLib::ReadWrite | BlackLib::NonBlock);
	if( !isOpened )
	{
		std::cout << "SPI DEVICE CAN\'T OPEN.;" << std::endl;
		exit(1);
	}
	else
	{
		cout<<"  \n OPEN spi in protocol: " <<endl;
	}
	sleep(1);
	uint8_t write[5] = {0x00,0x02,0x02,0x01,0x05};
	uint8_t write0 =0x03;
	uint8_t write1[3] = {0x02,0x00,0x00};
	uint8_t read[200];
	memset(read,0,sizeof(read));
	mySpi.transfer(write,read,sizeof(write),5000);
	while (read[0] != 8)                                      //wait bit 3 ( EX: '0000 1000')
		{
			read[0] = mySpi.transfer(write0,5000);
			//read[0] = read[0] & 0x08;//write poll 0x03
			printf("resceive data_protocol = %02X\r\n",read[0]);
			if(read[0] & 0x08)
			{
				printf("exit protocol \r\n");
				break;
			}

		}
	mySpi.transfer(write1,read,sizeof(write1),5000); //write command read data
	printf("resceive data_protocol[0] = %02X\r\n",read[0]);//print data
	printf("resceive data_protocol[1] = %02X\r\n",read[1]);//print data
	printf("resceive data_protocol[2] = %02X\r\n",read[2]);//print data
	sleep(1);
	if(read[1] == 0x00 && read[2] == 0x00)
	{
		printf("PROTOCOL SET \r\n");
		NFCReady = 1;//NFC is ready
		printf("NFCReady=%d \r\n",NFCReady );
	}
	else
	{
		 printf("RESPONSE TO SET PROTOCOL");
		 NFCReady = 0;// NOT NFC is ready
		 printf("NFCReady=%d \r\n",NFCReady );
	}
	sleep(1);
}

void Inventory_Command()
{
	BlackLib::BlackSPI  mySpi(BlackLib::SPI1_0,8,BlackLib::SpiMode0,500000);
	bool isOpened = mySpi.open( BlackLib::ReadWrite | BlackLib::NonBlock);
	if( !isOpened )
	{
		std::cout << "SPI DEVICE CAN\'T OPEN.;" << std::endl;
		exit(1);
	}
	else
	{
		cout<<"  \n OPEN spi in Inventory: " <<endl;
	}
	sleep(1);
	uint8_t write[6] = {0x00,0x04,0x03,0x26,0x01,0x00};
	uint8_t write0 = 0x03;
	uint8_t write1[50] = {0x02};
	uint8_t i,j=1,m,n;
//    write1[1] = 0x00;
//    write1[2] = 0x00;
	uint8_t read[500],read1[500];
	memset(read,0,sizeof(read));
	memset(read1,0,sizeof(read1));
	mySpi.transfer(write,read,sizeof(write),5000);
	while (read[0] != 8)                                      //wait bit 3 ( EX: '0000 1000')
			{
				read[0] = mySpi.transfer(write0,5000);
				read[0] = read[0] & 0x08;//write poll 0x03
				printf("resceive data_Inventory= %02X\r\n",read[0]);
				if(read[0] & 0x08)
				{
					printf("exit Inventory \r\n");
					break;
				}

			}
	mySpi.transfer(write1,read,sizeof(write1),5000); //write command read data
	sleep(2);
	if(read[1] == 128)
	{


			printf("TAG DETECTED:  \r\n");
			printf("UID: ");
			uint8_t len = read[2];
			for(i=1;i<len + 2;i++)
			{
				read1[j]=read[i];
				j++;
			}
			for(m=1;m<j;m++)
			{
				n=read1[m];
				printf("%02X \r\n",read1[m]);

			}
			if(read1[5] == 0x46 && read1[6] == 0xC7 && read1[7] == 0xBB && read1[8] == 0x76 && read1[9] == 0x00 )
			{
				 lift_pallet();
			}
			else if(read1[5] == 0x46 && read1[6] == 0x10 && read1[7] == 0xB9 && read1[8] == 0x4E  && read1[9] == 0x50)
			{
				 turn_right();
			}
			else
			{

			}
//		printf("TAG DETECTED:  \r\n");
//		printf("UID :%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X  \r\n",read[1],read[2],read[3],read[4],read[5],read[6],read[7],
//																						read[8],read[9],read[10],read[11],read[12],read[13],read[14]);
//		printf(" ");
//		sleep(1);
	}
	else
	{
		printf("NO TAG DETECTED:%02X%02X  \r\n",read[1],read[2]);
	}

}
void lift_pallet()
{
	printf("lift_pallet");
}
void turn_right()
{
	printf("turn_right");
}
int Hex2Asc(char *Dest,unsigned char *Src,int SrcLen)
{
	int i;
	for ( i = 0; i < SrcLen; i ++ )
	{
		sprintf(Dest + i * 2,"%02X",Src[i]);
	}
	Dest[i * 2] = 0;
	return 0;
}
//#include <iostream>
//#include <termios.h>
//#include <stdio.h>
//#include <unistd.h>
//#include <fcntl.h>
//#include <signal.h>
//#include <stdint.h>
//#include <termios.h>
//#include <fcntl.h>
//#include <stdlib.h>
//#define BAUDRATE B9600
//#define MODEMDEVICE "/dev/ttyO1"
//#define _POSIX_SOURCE 1 /* POSIX compliant source */
//#define FALSE 0
//#define TRUE 1
//
//volatile int STOP=FALSE;
//void signal_handler_IO (int signum);   /* definition of signal handler */
//int wait_flag=TRUE;                    /* TRUE while no signal received */
//
//int main()
//  {
//    int fd,c, res;
//    struct termios oldtio,newtio;
//    struct sigaction saio;           /* definition of signal action */
//    char buf[255];
//
//    /* open the device to be non-blocking (read will return immediatly) */
//    fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY | O_NONBLOCK);
//    if (fd <0)
//    {
//    	perror(MODEMDEVICE);
//    	exit(-1);
//    }
//
//    /* install the signal handler before making the device asynchronous */
//    saio.sa_handler = signal_handler_IO;
//    //saio.sa_mask = 0;
//    saio.sa_flags = 0;
//    saio.sa_restorer = NULL;
//    sigaction(SIGIO,&saio,NULL);
//
//    /* allow the process to receive SIGIO */
//    fcntl(fd, F_SETOWN, getpid());
//    /* Make the file descriptor asynchronous (the manual page says only
//       O_APPEND and O_NONBLOCK, will work with F_SETFL...) */
//    fcntl(fd, F_SETFL, FASYNC);
//
//    tcgetattr(fd,&oldtio); /* save current port settings */
//    /* set new port settings for canonical input processing */
//    newtio.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
//    newtio.c_iflag = IGNPAR | ICRNL;
//    newtio.c_oflag = 0;
//    newtio.c_lflag = ICANON;
//    newtio.c_cc[VMIN]=1;
//    newtio.c_cc[VTIME]=0;
//    tcflush(fd, TCIFLUSH);
//    tcsetattr(fd,TCSANOW,&newtio);
//
//    /* loop while waiting for input. normally we would do something
//       useful here */
//    while (STOP==FALSE) {
//      printf("wait\n");usleep(100000);
//      /* after receiving SIGIO, wait_flag = FALSE, input is available
//         and can be read */
//      if (wait_flag==FALSE) {
//        res = read(fd,buf,255);
//        buf[res]=0;
//        printf(":%s:%d\n", buf, res);
//        if (res==1) STOP=TRUE; /* stop loop if only a CR was input */
//        wait_flag = TRUE;      /* wait for new input */
//      }
//    }
//    /* restore old port settings */
//    tcsetattr(fd,TCSANOW,&oldtio);
//  }
//
//  /***************************************************************************
//  * signal handler. sets wait_flag to FALSE, to indicate above loop that     *
//  * characters have been received.                                           *
//  ***************************************************************************/
//
//  void signal_handler_IO (int signum)
//  {
//	  if(signum == SIGIO)
//	  {
//		  printf("received SIGIO signal.\n");
//
//		  printf("signum:%d %d",signum, SIGIO);
//	  }
//
//    wait_flag = FALSE;
//  }

