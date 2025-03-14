#include "ioControl.hpp"

#include "esp_log.h"

static const char* LOG_TAG{ "IoControl" };

IoControl::IoControl()
{
ESP_LOGI(LOG_TAG, "Constructed");
}

IoControl::~IoControl()
{
    ESP_LOGI(LOG_TAG, "Destructed");
}
