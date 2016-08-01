set(__LINARO 
		/usr/local/linaro
	)
set(__PREFIX
		arm-linux-gnueabihf
	)

set(__SYSROOT
		/workspace/beagle_sysroot
	)
set(__CROSS_LIB_PATH
		${__LINARO}/${__PREFIX}/${__PREFIX}/libc
	)

set(CMAKE_SYSTEM_NAME 
	Linux
	)
set(CMAKE_C_COMPILER 
		${__LINARO}/${__PREFIX}/bin/${__PREFIX}-gcc
	)
set(CMAKE_CXX_COMPILER
		${__LINARO}/${__PREFIX}/bin/${__PREFIX}-g++
	)
set(CMAKE_CXX_FLAGS
		"-L${__SYSROOT}/usr/lib/${__PREFIX} -L${__SYSROOT}/usr/lib -laprutil-1 -lapr-1 -lexpat -luuid -lcrypt -ldl -licuuc -lrt -licui18n -licudata -lpthread -lz -lutil -lbz2"
	)
set(CMAKE_SYSROOT
		${__SYSROOT}
	)
set(CMAKE_FIND_ROOT_PATH
		${__SYSROOT}
	)

set(CMAKE_VERBOSE_MAKEFILE
		TRUE
	)

MESSAGE( STATUS "CMAKE_ROOT: " ${CMAKE_ROOT} )
MESSAGE( STATUS "CMAKE_LIBRARY_PATH: " ${CMAKE_LIBRARY_PATH} )
MESSAGE( STATUS "CMAKE_SYSTEM: " ${CMAKE_SYSTEM} )
MESSAGE( STATUS "CMAKE_VERBOSE_MAKEFILE: " ${CMAKE_VERBOSE_MAKEFILE} )
MESSAGE( STATUS "CMAKE_C_FLAGS: " ${CMAKE_C_FLAGS} )
MESSAGE( STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS} )

# set(CMAKE_LIBRARY_PATH
# 	${CMAKE_LIBRARY_PATH}
# 	${__CROSS_LIB_PATH}
# 	)
# set (CMAKE_SYSTEM_LIBRARY_PATH
# 	${CMAKE_SYSTEM_LIBRARY_PATH}
# 	${__CROSS_LIB_PATH}
# 	)
# set (CMAKE_LINK_LIBRARY_FLAG 
# 	${CMAKE_LINK_LIBRARY_FLAG}
# 	${__CROSS_LIB_PATH}
# 	)

# link_directories(
# 	${__CROSS_LIB_PATH}
# 	)

# Have to set this one to BOTH, to allow CMake to find rospack
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
