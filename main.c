#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "stdbool.h"

// These are examples of timer parameters.
#define TIMER0_COUNT    1000
#define ONE_SHOT        true
#define CONTINUOUS      false

typedef enum {Off, Red, Green, Yellow, Blue, Magenta, Cyan, White} colors;

// Initialization functions
void Init_Launchpad(void);
void Init_GPIO(void);
// TODO: Write the timer initialization.
// - This function has been written to pass initialization parameters instead of hard-coding them in the function.
// - Write the function to use the parameters, then insert the parameters into the function call.
// - These are not all of the parameters that the Timer init functions use. You could add more.
// - With that said, the HAL coding model should still seek to hide the microcontroller-specific details.
void Init_Timer0(unsigned count, bool oneShot);

// GPIO Driver Code
char Get_Status_Launchpad_Button1(void);
char Get_Status_Launchpad_Button2(void);
void TurnOn_Launchpad_LED1(void);
void TurnOff_Launchpad_LED1(void);
// TODO: Map the color of LED2 to the value of the current color.
void Update_Launchpad_LED2(colors color);

// Timer Driver Code
// TODO: Check the timer for completion.
bool Timer0_Expired(unsigned timer_id);

int main(void)
{
    colors current_color = Off;

    Init_Launchpad();
    Init_GPIO();
    Init_Timer0(TIMER0_COUNT, CONTINUOUS);   // Note how the init parameters are passed to the Init_Timer function.
    Update_Launchpad_LED2(current_color);

    while(1)
    {
        // We want to use the timer so that this code is not blocked.
        if((!(Get_Status_Launchpad_Button1())) || (!(Get_Status_Launchpad_Button2())))
            TurnOn_Launchpad_LED1();
        else
            TurnOff_Launchpad_LED1();

        // TODO: Write the control structure that checks the timer for completion.

        // TODO: If the check succeeds:
        // - Update the value of current_color. (Remember to boundary check.)
        // - Update the color of LED2.
    }
}

void Init_Launchpad()
{
    // Stop Watchdog Timer.
    WDT_A_hold(WDT_A_BASE);
}

void Init_GPIO()
{
    // Initialize LaunchPad pushbuttons.
    GPIO_setAsInputPinWithPullUpResistor (GPIO_PORT_P1, GPIO_PIN1);
    GPIO_setAsInputPinWithPullUpResistor (GPIO_PORT_P1, GPIO_PIN4);

    // Initialize LaunchPad LEDs.
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);   // LaunchPad LED1
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0);   // LaunchPad LED2 (Red)
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN1);   // LaunchPad LED2 (Green)
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2);   // LaunchPad LED2 (Blue)
}

void Init_Timer0(unsigned count, bool oneShot)
{
    // TODO: Configure Timer0 in 32-bit Periodic Mode. Choose a pre-scale value in conjunction with your count value.
    // TODO: Set the initial count value using the function parameter.
    // TODO: Start the timer in the mode indicated by the function parameter.
}

char Get_Status_Launchpad_Button1()
{
    return GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN1);
}

char Get_Status_Launchpad_Button2()
{
    return GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN4);
}

void TurnOn_Launchpad_LED1()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
}
void TurnOff_Launchpad_LED1()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
}

void Update_Launchpad_LED2(colors color)
{
    // TODO: Map the color of LED2 to the value of the current color.
    // - Use an if-else or switch-case structure containing DriverLib functions.
}

bool Timer0_Expired(unsigned timer_id)
{
    // TODO: Check Timer0 for completion.
    // - A function that accomplishes this task is in the lecture slides. You will need to explain why it works.
}
