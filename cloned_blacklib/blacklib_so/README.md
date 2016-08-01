# Blacklib-shared-library

Edit toolschain and rootfs in Makefile

$ make

# Development:
	v3_0: for old linux kernel (3.8 ~ unknown) which has old bone_capemgr path

	v4_0: for new linux kernel (4.4.9 tested).
	      NOTE: version 4.1.x may cause bugs in capemgr as reported by community
	      Function tested:
	      	- ADC: AIN0
		- UART: UART1,2,3,4
