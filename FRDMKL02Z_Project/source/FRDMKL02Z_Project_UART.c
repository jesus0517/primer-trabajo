//Jesús David Mojica
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL02Z4.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "sdk_hal_uart0.h"


        void Delay(void){
            volatile uint32_t p=0;
            for (p=0; p<1000000;p++){
                __asm("NOP");
            }



        }
        int main(void) {
              /* Init board hardware. */
            BOARD_InitBootPins();
            BOARD_InitBootClocks();
            BOARD_InitBootPeripherals();
        #ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
            /* Init FSL debug console. */
            BOARD_InitDebugConsole();
        #endif



            (void)uart0Inicializar(115200);



            while(1) {
                status_t status;
                uint8_t nuevo_byte;

                if(uart0NuevosDatosEnBuffer()>0){
                    status=uart0LeerByteDesdeBufferCircular(&nuevo_byte);
                    if(status==kStatus_Success){
                        printf("dato:%c\r\n",nuevo_byte);
                    }else{
                        printf("error\r\n");
                    }
                      if(nuevo_byte=='P') {//Prende todos los leds
                          GPIO_PortClear(GPIOB,1u<<BOARD_LED_GREEN_GPIO_PIN);//Verde enciende
                          Delay();
                          GPIO_PortClear(GPIOB,1u<<BOARD_LED_RED_GPIO_PIN);//Rojo enciende
                          Delay();
                          GPIO_PortClear(GPIOB,1u<<BOARD_LED_BLUE_GPIO_PIN);//Azul enciende
                          Delay();
                                                }
                      if(nuevo_byte=='p'){// Permite apagar todos los leds
                          GPIO_PortSet(GPIOB,1u<<BOARD_LED_GREEN_GPIO_PIN);//Verde apagado
                          Delay();
                          GPIO_PortSet(GPIOB,1u<<BOARD_LED_RED_GPIO_PIN);//Rojo apagado
                          Delay();
                          GPIO_PortSet(GPIOB,1u<<BOARD_LED_BLUE_GPIO_PIN);//Azul apagado
                          Delay();
                                                }
                      if(nuevo_byte=='R'){
                            GPIO_PortClear(GPIOB,1u<<BOARD_LED_RED_GPIO_PIN);//Rojo enciende
                            Delay();
                        }
                      if(nuevo_byte=='r'){
                          GPIO_PortSet(GPIOB,1u<<BOARD_LED_RED_GPIO_PIN);//Rojo apagado
                           Delay();
                      }
                      if(nuevo_byte=='A'){
                          GPIO_PortClear(GPIOB,1u<<BOARD_LED_BLUE_GPIO_PIN);//Azul enciende
                          Delay();
                          }
                      if(nuevo_byte=='a'){
                        GPIO_PortSet(GPIOB,1u<<BOARD_LED_BLUE_GPIO_PIN);//Azul Apagado
                        Delay();
                              }
                      if(nuevo_byte=='V'){
                          GPIO_PortClear(GPIOB,1u<<BOARD_LED_GREEN_GPIO_PIN);//Verde enciende
                          Delay();
                                   }
                      if(nuevo_byte=='v'){
                          GPIO_PortSet(GPIOB,1u<<BOARD_LED_GREEN_GPIO_PIN);//Verde apagado
                          Delay();
                                                }
                      if (nuevo_byte=='N'){
                    	  while(1) // Secuencia de colores
                    	  {
                      	GPIO_PortSet(GPIOB, 1u << BOARD_LED_RED_GPIO_PIN);
                      	Delay();
                      	GPIO_PortClear(GPIOB, 1u << BOARD_LED_BLUE_GPIO_PIN);
                      	Delay();
                    	GPIO_PortSet(GPIOB, 1u << BOARD_LED_BLUE_GPIO_PIN);
                    	Delay();
                      	GPIO_PortClear(GPIOB, 1u << BOARD_LED_GREEN_GPIO_PIN);
                      	Delay();
                    	GPIO_PortSet(GPIOB, 1u << BOARD_LED_GREEN_GPIO_PIN);
                    	Delay();
                      	GPIO_PortClear(GPIOB, 1u << BOARD_LED_RED_GPIO_PIN);
                      	Delay();
                    	  }
                      }

                      }
            }

            return 0 ;
        }

//                if (uart0NuevosDatosEnBuffer()==1){//Dato del UART listo
//
//                	switch(status=uart0LeerByteDesdeBufferCircular(&nuevo_byte))//Lectura del dato UART
//                	case'R': nuevo_byte='R';break;
//                	case'r': nuevo_byte='r';break;
////                	case'A': nuevo_byte='A';break;
////                	case'a': nuevo_byte='a';break;
////                	case'V': nuevo_byte='V';break;
////                	case'v': nuevo_byte='v';break;
////                	default : break;
//                }
//            }
//            if (nuevo_byte=='R'){
//            	printf("dato:%c\r\n",nuevo_byte);
//            	GPIO_PortClear(GPIOB,1u<<BOARD_LED_RED_GPIO_PIN);//Rojo prende
//            	Delay();
//            }
//            if (nuevo_byte=='r'){
//            	printf("dato:%c\r\n",nuevo_byte);
//                        	GPIO_PortSet(GPIOB,1u<<BOARD_LED_RED_GPIO_PIN);//Rojo prende
//                        	Delay();
//                        }
//
//
//        return 0;
//        }
