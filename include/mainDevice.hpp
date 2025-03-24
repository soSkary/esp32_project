#pragma once

#include "communicator.hpp"
#include "ioControl.hpp"
#include "lightControl.hpp"
#include "movementControl.hpp"

class MainDevice
{
public:
    MainDevice();
    ~MainDevice();

    void initialize();

    void execute();
private:
    Communicator    m_remoteDevice;     // communication to e.g. remote controller
    IoControl       m_io;               // for controlling physical io-pins
    
    LightControl    m_led1;            // logical control of LEDs
    LightControl    m_led2;            // logical control of LEDs
    LightControl    m_led3;            // logical control of LEDs
    MovementControl m_movementControl; // logical control of movement
};
