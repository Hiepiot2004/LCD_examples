
#include <stdio.h>
#include <unistd.h>      // for usleep
#include "driver/i2c.h"  // for I2C communication
#include "esp_log.h"     // for ESP_LOGI
#include "lcd.h"

void app_main(void)
{

    ESP_ERROR_CHECK(i2c_master_init());
    ESP_LOGI(TAG, "I2C initialized successfully");

    lcd_init();
    lcd_clear();

    // Example 1: Display static text
    lcd_put_cur(0, 0);
    lcd_send_string("Hello World!");

    lcd_put_cur(1, 0);
    lcd_send_string("from ESP32");

    // // Example 2: Display a formatted value
    // char buffer[16];
    // float num = 1234.56;

    // lcd_clear();  // Clear before displaying new content
    // sprintf(buffer, "Val=%.2f", num);  // Format float to 2 decimal places
    // lcd_put_cur(0, 0);
    // lcd_send_string(buffer);
}
