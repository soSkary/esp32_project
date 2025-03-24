#include "lightControl.hpp"

#include "esp_log.h"

static const char* LOG_TAG{ "LightControl" };

LightControl::LightControl()
{
    ESP_LOGI(LOG_TAG, "Constructed");
}

LightControl::~LightControl()
{

    ESP_LOGI(LOG_TAG, "Destructed");
}

esp_err_t LightControl::initialize( ledc_timer_config_t timer_config, ledc_channel_config_t channel_config )
{
    m_timer_config = timer_config;
    m_channel_config = channel_config;
    
    esp_err_t error_code{ ledc_timer_config(&m_timer_config) };

    if (error_code != ESP_OK)
    {
        return error_code;
    }

    error_code = ledc_channel_config(&m_channel_config);
    return error_code;
}
