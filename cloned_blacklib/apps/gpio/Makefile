CXX=$(CROSS_COMPILE)g++

INCLUDES=-I$(CROSS_INCLUDE) -I../../blacklib_so/include

CPPFLAGS=-D__GXX_EXPERIMENTAL_CXX0X__ -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8

CXXFLAGS=-std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -pthread $(CPPFLAGS) $(INCLUDES)

LDFLAGS=-lpthread -lBlackLib

LDLIBS=-L$(CROSS_LIB) -L../../blacklib_so

RM=rm -f

SOURCES=gpio.cpp

OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=gpio


all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(LDLIBS) $(OBJECTS) $(LDFLAGS) -o $@
	$(RM) ./*.o

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) $(OBJECTS)


