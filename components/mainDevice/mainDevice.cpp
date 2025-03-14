#include "mainDevice.hpp"
#include "esp_log.h"

static const char* LOG_TAG{ "MainDevice" };

MainDevice::MainDevice()
{
    ESP_LOGI(LOG_TAG, "Constructed");
}

MainDevice::~MainDevice()
{
    ESP_LOGI(LOG_TAG, "Destructed");
}
