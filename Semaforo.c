#include <stdio.h>
#include "pico/stdlib.h"


// Defina os pinos do LED RGB (substitua pelos pinos corretos da sua placa)
#define LED_RED 13  // Pino para o vermelho
#define LED_GREEN 11 // Pino para o verde
#define LED_BLUE 12  // Pino para o azul

void setup_leds() {
    // Configura os pinos do LED RGB como saída
    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
}

void set_color(int red, int green, int blue) {
    gpio_put(LED_RED, red);    // Controla o vermelho
    gpio_put(LED_GREEN, green); // Controla o verde
    gpio_put(LED_BLUE, blue);  // Controla o azul
}

void semaforo() {
    // Vermelho: 5 segundos
    set_color(1, 0, 0); // Vermelho
    sleep_ms(5000);

    // Amarelo: 2 segundos
    set_color(1, 1, 0); // Amarelo (vermelho + verde)
    sleep_ms(2000);

    // Verde: 5 segundos
    set_color(0, 1, 0); // Verde
    sleep_ms(5000);


}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial (opcional)

    setup_leds(); // Configura os LEDs

    while (true) {
        semaforo(); // Executa o ciclo do semáforo
    }
}
