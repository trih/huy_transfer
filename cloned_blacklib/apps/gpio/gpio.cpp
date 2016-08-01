#include "BlackLib/BlackLib.h"
#include <iostream>
#include <unistd.h>
#include <bitset>

//Define bits for LED
#define T1      0
#define T2      1
#define T3      2
#define T4      3
#define T5      4

int main(int argc, const char * argv[]) {

        std::bitset<5> trackingValue_bitset;
        uint32_t trackingValue = 0;
        BlackLib::BlackGPIO t1Value(BlackLib::GPIO_65, BlackLib::input);
        BlackLib::BlackGPIO t2Value(BlackLib::GPIO_66, BlackLib::input);
        BlackLib::BlackGPIO t3Value(BlackLib::GPIO_67, BlackLib::input);
        BlackLib::BlackGPIO t4Value(BlackLib::GPIO_68, BlackLib::input);
        BlackLib::BlackGPIO t5Value(BlackLib::GPIO_69, BlackLib::input);

        while (1) {
                trackingValue_bitset[T1] = t1Value.getNumericValue();
                trackingValue_bitset[T2] = t2Value.getNumericValue();
                trackingValue_bitset[T3] = t3Value.getNumericValue();
                trackingValue_bitset[T4] = t4Value.getNumericValue();
                trackingValue_bitset[T5] = t5Value.getNumericValue();

                trackingValue = (int)trackingValue_bitset.to_ulong();

                std::cout << trackingValue << std::endl;

                sleep(1);
        }

        return 0;
}