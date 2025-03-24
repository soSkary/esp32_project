idf_component_register( SRCS lightControl.cpp 
                        INCLUDE_DIRS . ${CMAKE_SOURCE_DIR}/include
                        REQUIRES esp_common esp_driver_ledc esp_driver_gpio
)
