#include "mainDevice.hpp"

extern "C" void app_main(void)
{
    MainDevice mainDevice{};
    mainDevice.initialize();
    mainDevice.execute();
}
