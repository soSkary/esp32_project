#include "movementControl.hpp"
#include "esp_log.h"

static const char* LOG_TAG{ "MovementControl" };

MovementControl::MovementControl()
{
    ESP_LOGI(LOG_TAG, "Constructed");
}

MovementControl::~MovementControl()
{
    ESP_LOGI(LOG_TAG, "Destructed");
}
