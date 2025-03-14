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
