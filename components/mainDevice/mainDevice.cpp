#include "mainDevice.hpp"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char* LOG_TAG{ "MainDevice" };

MainDevice::MainDevice()
{
    ESP_LOGI(LOG_TAG, "Constructed");
}

MainDevice::~MainDevice()
{
    ESP_LOGI(LOG_TAG, "Destructed");
}

void MainDevice::initialize()
{
    /* Initialize leds
    * LED 1
    */
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_HIGH_SPEED_MODE,   // timer mode
        .duty_resolution = LEDC_TIMER_13_BIT, // resolution of PWM duty
        .timer_num = LEDC_TIMER_0,            // timer index
        .freq_hz = 4000,                      // frequency of PWM signal
        .clk_cfg = LEDC_AUTO_CLK,             // Auto select the source clock
        // .deconfigure = false
    };

    // Note: if different channels use one timer,
    //       then frequency and bit_num of these channels
    //       will be the same
    ledc_channel_config_t ledc_channel = {
            .gpio_num = 25,                     // GPIO number where LED is connected to
            .speed_mode = LEDC_HIGH_SPEED_MODE, // speed mode, either high or low
            .channel = LEDC_CHANNEL_0,          // controller's channel number
            // .intr_type = ,
            .timer_sel = LEDC_TIMER_0,          // timer servicing selected channel
            .duty = 0,                          // output duty cycle, set initially to 0
            .hpoint = 0,
            // .sleep_mode = ,  
            // .output_invert = 0
    };
    ESP_ERROR_CHECK(m_led1.initialize(ledc_timer, ledc_channel));

    /*
    * LED 2
    */
    ledc_channel.gpio_num = 26;
    ESP_ERROR_CHECK(m_led2.initialize(ledc_timer, ledc_channel));

    /*
    * LED 3
    */
    ledc_channel.gpio_num = 27;
    ESP_ERROR_CHECK(m_led2.initialize(ledc_timer, ledc_channel));


}

void MainDevice::execute()
{
    while (true)
    {
        uint16_t duty{ 8192 };
        for (uint8_t i{ 0 }; i < 8; ++i)
        {
            ESP_LOGI(LOG_TAG, "Leds at %d",duty);
            ESP_ERROR_CHECK(ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, duty));
            ESP_ERROR_CHECK(ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0));
            vTaskDelay(pdMS_TO_TICKS(2000));
            duty -= 1024;
        }
    }
}   
