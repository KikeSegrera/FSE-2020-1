#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "driver/uart.h"
#include "soc/uart_struct.h"
#include "string.h"
#include "driver/gpio.h"

static const int RX_BUF_SIZE = 1024;

#define LED 2
#define BOTON 4

void init() {
    const uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };
    uart_param_config(UART_NUM_0, &uart_config);
    uart_driver_install(UART_NUM_0, RX_BUF_SIZE * 2, 0, 0, NULL, 0);

    gpio_pad_select_gpio(LED);
	gpio_set_direction(LED, GPIO_MODE_OUTPUT);
	gpio_pad_select_gpio(BOTON);
	gpio_set_direction(BOTON, GPIO_MODE_INPUT);
}

int sendData(const char* logName, const char* data)
{
    const int len = strlen(data);
    const int txBytes = uart_write_bytes(UART_NUM_0, data, len);
    ESP_LOGI(logName, "Escribo %d bytes", txBytes);
    return txBytes;
}

static void tx_task()
{
    static const char *TX_TASK_TAG = "Transmision";
    esp_log_level_set(TX_TASK_TAG, ESP_LOG_INFO);
    while (1) {
    	if (gpio_get_level(BOTON) == 1){
        	sendData(TX_TASK_TAG, "Boton presionado\n");
    	}
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

static void rx_task()
{
    static const char *RX_TASK_TAG = "Recepcion";
    esp_log_level_set(RX_TASK_TAG, ESP_LOG_INFO);
    uint8_t* data = (uint8_t*) malloc(RX_BUF_SIZE+1);
    while (1) {
        const int rxBytes = uart_read_bytes(UART_NUM_0, data, RX_BUF_SIZE, 500 / portTICK_RATE_MS);
        if (rxBytes > 0) {
            data[rxBytes] = 0;
            if (strcmp((const char *)data, "1") == 0){
				gpio_set_level(LED, 1);}
			if (strcmp((const char *)data, "0") == 0){
				gpio_set_level(LED, 0);}
			ESP_LOGI(RX_TASK_TAG, "Leo %d bytes: '%s'", rxBytes, data);
        }
    }
    free(data);
}

void app_main()
{
	init();
    
    xTaskCreate(rx_task, "uart_rx_task", 1024*2, NULL, configMAX_PRIORITIES, NULL);
    xTaskCreate(tx_task, "uart_tx_task", 1024*2, NULL, configMAX_PRIORITIES-1, NULL);
}
