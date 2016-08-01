CXX=${CROSS_COMPILE}g++

INCLUDES=-I${CROSS_INCLUDE} -I./include/BlackLib

CPPFLAGS=-D__GXX_EXPERIMENTAL_CXX0X__ -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8

CXXFLAGS=-std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -pthread $(CPPFLAGS) $(INCLUDES)

LDFLAGS=-lpthread

LDLIBS=-L${CROSS_LIB}

RM=rm -f

SOURCES=./BlackADC/BlackADC.cpp ./BlackDirectory/BlackDirectory.cpp  ./BlackGPIO/BlackGPIO.cpp ./BlackI2C/BlackI2C.cpp ./BlackMutex/BlackMutex.cpp ./BlackPWM/BlackPWM.cpp ./BlackSPI/BlackSPI.cpp ./BlackThread/BlackThread.cpp ./BlackTime/BlackTime.cpp  ./BlackUART/BlackUART.cpp ./BlackCore/BlackCore.cpp

OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=libBlackLib.so


all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(LDLIBS) $(OBJECTS) $(LDFLAGS) -shared -o $@
	$(RM) ./*.o

.cpp.o:
	$(CXX) -c -fpic $(CXXFLAGS) $< -o $@

install:
	install lib

clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)

