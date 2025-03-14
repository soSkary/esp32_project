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

    void execute();
private:
    Communicator    m_remoteDevice;     // communication to e.g. remote controller
    IoControl       m_io;               // for controlling physical io-pins
    
    LightControl    m_lightControl;     // logical control of LEDs
    MovementControl m_movementControl; // logical control of movement
};
