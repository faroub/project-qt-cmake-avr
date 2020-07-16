/**
 * @file ha_m328p.h
 * @brief Header file for the hardware abstraction macros of the Atmega328p
 *
 * @author Farid Oubbati (https://github.com/faroub)
 * @date March 2020
*/
#ifndef HAM329P_H
#define HAM329P_H

#ifndef HABASE_H
    #error "don't use this file directly! Please include only ha_base.h!"
#endif

// PushButton defines
#define PUSHBUTTON_DEBOUNCE_TIME_US 1000 // microseconds to wait for next check
#define PUSHBUTTON_SAMPLING     12           // number of times a push button must be pressed


// USART defines
#include <util/setbaud.h>

#define   USART0_SET_BAUDRATE_HIGH_REGISTER     UBRR0H = UBRRH_VALUE
#define   USART0_SET_BAUDRATE_LOW_REGISTER      UBRR0L = UBRRL_VALUE

#define   USART0_ENABLE_ASYNC_TRANSMISSION_MODE     UCSR0C &= ~((1 << UMSEL01) | (1 << UMSEL00))
#define   USART0_ENABLE_SYNC_TRANSMISSION_MODE      UCSR0C = (UCSR0C & ~(1 << UMSEL01)) | (1 << UMSEL00)
#define   USART0_ENABLE_MASTER_SPI_MODE             UCSR0C |= (1 << UMSEL01) | (1 << UMSEL00)


#define   USART0_ENABLE_DOUBLE_SPEED_MODE
#define   USART0_DISABLE_DOUBLE_SPEED_MODE

#if USE_2X
    #undef  USART0_ENABLE_DOUBLE_SPEED_MODE
    #define USART0_ENABLE_DOUBLE_SPEED_MODE UCSR0A |= (1 << U2X0)
    #warning "double speed operation activated"
#else
    #undef  USART0_DISABLE_DOUBLE_SPEED_MODE
    #define USART0_DISABLE_DOUBLE_SPEED_MODE UCSR0A &= ~(1 << U2X0)
#endif

#define   USART0_ENABLE_EVEN_PARITY_MODE    UCSR0C = (1 << UPM01) | (UCSR0C & ~(1 << UPM00))
#define   USART0_ENABLE_ODD_PARITY_MODE     UCSR0C |=   ((1 << UPM01) | (1 << UPM00))
#define   USART0_DISABLE_PARITY_MODE        UCSR0C &= ~((1 << UPM01) | (1 << UPM00))


#define   USART0_SET_ONE_STOP_BIT   UCSR0C &= ~(1 << USBS0)
#define   USART0_SET_TWO_STOP_BITS  UCSR0C |= (1 << USBS0)


#define   USART0_SET_9BIT_FRAME_SIZE   \
    do { \
        UCSR0C |= ((1 << UCSZ01) | (1 << UCSZ00)); \
        UCSR0B |= (1 << UCSZ02); \
    } while (0)

#define   USART0_SET_8BIT_FRAME_SIZE   \
    do { \
        UCSR0C |= ((1 << UCSZ01) | (1 << UCSZ00)); \
        UCSR0B &= ~(1 << UCSZ02); \
    } while (0)

#define   USART0_SET_7BIT_FRAME_SIZE  \
    do { \
        UCSR0C = (1 << UCSZ01) | (UCSR0C & ~(1 << UCSZ00)); \
        UCSR0B &= ~(1 << UCSZ02); \
    } while (0)
#define   USART0_SET_6BIT_FRAME_SIZE \
    do { \
        UCSR0C = (UCSR0C & ~(1 << UCSZ01)) | (1 << UCSZ00); \
        UCSR0B &= ~(1 << UCSZ02); \
    } while (0)
#define   USART0_SET_5BIT_FRAME_SIZE \
    do { \
        UCSR0C &= ~((1 << UCSZ01) | (1 << UCSZ00)); \
        UCSR0B &= ~(1 << UCSZ02); \
    } while (0)


#define   USART0_ENABLE_TRANSMITTER      UCSR0B |=   1 << TXEN0
#define   USART0_DISABLE_TRANSMITTER     UCSR0B &= ~(1 << TXEN0)



#define   USART0_ENABLE_RECEIVER         UCSR0B |=   1 << RXEN0
#define   USART0_DISABLE_RECEIVER        UCSR0B &= ~(1 << RXEN0)



#define   USART0_CONTROL_STATUS_REGISTER UCSR0A
#define   USART0_DATA_REGISTER           UDR0




#define   USART0_FRAME_ERROR             FE0

#define   USART0_DATA_OVERRUN            DOR0

#define   USART0_PARITY_ERROR            UPE0


#define   USART0_ENABLE_DATA_REGISTER_EMPTY_INTERRUPT   UCSR0B |=   1 << UDRIE0
#define   USART0_DISABLE_DATA_REGISTER_EMPTY_INTERRUPT  UCSR0B &= ~(1 << UDRIE0)

#define   USART0_ENABLE_RECEIVE_COMPLETE_INTERRUPT   UCSR0B |=   1 << RXCIE0
#define   USART0_DISABLE_RECEIVE_COMPLETE_INTERRUPT  UCSR0B &= ~(1 << RXCIE0)

#define   USART0_ENABLE_TRANSMIT_COMPLETE_INTERRUPT   UCSR0B |=   1 << TXCIE0
#define   USART0_DISABLE_TRANSMIT_COMPLETE_INTERRUPT  UCSR0B &= ~(1 << TXCIE0)



#define   USART0_RECEIVE_COMPLETE_INTERRUPT     USART_RX_vect

#define   USART0_TRANSMIT_COMPLETE_INTERRUPT    USART_TX_vect

#define   USART0_DATA_REGISTER_EMPTY_INTERRUPT  USART_UDRE_vect


// ADC defines

#define   ADC_SELECT_REF_VOLTAGE(refVoltage)         ADMUX &= 0x1F; ADMUX |= refVoltage << 6

#define   ADC_ADJUST_RESULT_LEFT            ADMUX |=  1 << ADLAR
#define   ADC_ADJUST_RESULT_RIGHT           ADMUX &= ~(1 << ADLAR)

#define   ADC_SELECT_ANALOG_INPUT(pinNumber)         ADMUX &= 0xF0; ADMUX |= pinNumber
#define   ADC_DISABLE_DIGITAL_INPUT_REGISTER(pinNumber)         DIDR0 &= 0xC0; DIDR0 |= pinNumber


#define   ADC_ENABLE            ADCSRA |=  1 << ADEN
#define   ADC_DISABLE           ADCSRA &= ~(1 << ADEN)

#define   ADC_START_CONVERSION            ADCSRA |=  1 << ADSC
#define   ADC_STOP_CONVERSION           ADCSRA &= ~(1 << ADSC)

#define   ADC_ENABLE_AUTOTRIGGER          ADCSRA |=   1 << ADATE
#define   ADC_DISABLE_AUTOTRIGGER        ADCSRA &= ~(1 << ADATE)

#define   ADC_ENABLE_CONVERSION_COMPLETE_INTERRUPT   ADCSRA |=   1 << ADIE
#define   ADC_DISABLE_CONVERSION_COMPLETE_INTERRUPT  ADCSRA &= ~(1 << ADIE)

#define   ADC_SELECT_CLOCK_PRESCALER(clockPrescaler)         ADCSRA &= 0xF8; ADCSRA |= clockPrescaler


#define   ADC_SELECT_AUTO_TRIGGER_SOURCE(triggerSource)         ADCSRB &= 0xF8; ADCSRB |= triggerSource


#define   ADC_CONVERSION_COMPLETE_INTERRUPT  ADC_vect




#endif

