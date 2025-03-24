#pragma once
#include "driver/ledc.h"

class LightControl
{
public:
    LightControl();
    ~LightControl();

    esp_err_t initialize(ledc_timer_config_t timer_config, ledc_channel_config_t channel_config);
private:
    ledc_timer_config_t     m_timer_config{};
    ledc_channel_config_t   m_channel_config{};
};
