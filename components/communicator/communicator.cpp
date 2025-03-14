#include "communicator.hpp"

#include "esp_log.h"

static const char* LOG_TAG{ "Communicator" };

Communicator::Communicator()
{
    ESP_LOGI(LOG_TAG, "Constructed");
}

Communicator::~Communicator()
{
    ESP_LOGI(LOG_TAG, "Destructed");
}

