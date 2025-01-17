#include "motor42.h"
#include <stdio.h>
#include <unistd.h>

#include "cmsis_os2.h"
#include "ohos_init.h"
#include "iot_gpio.h"

#include "iot_pwm.h"
#include "iot_errno.h"
#include "hi_io.h"

#define STEEP_GPIO 9
#define DIR_GPIO 11
#define MOTOR_TASK_STACK_SIZE 1024
#define COUNT1 50
#define COUNT2 100
#define GPIO_HIGH       (0)
#define GPIO_LOW        (1)
#define motorperiod 20000   //T=40ms

void left_move_30angle(void)
{
    IoTGpioSetOutputVal(DIR_GPIO, 1);//2
    for (int i = 0; i < 15; i++) 
    {
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_HIGH);
        usleep(motorperiod); 
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_LOW);
        usleep(motorperiod);
    }
    printf("left_move_30angle finished!\r\n");
}

void left_move_60angle(void)
{
    IoTGpioSetOutputVal(DIR_GPIO, 1);//3
    for (int i = 0; i < 28; i++) 
    {
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_HIGH);
        usleep(motorperiod); 
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_LOW);
        usleep(motorperiod);
    }
    printf("left_move_60angle finished!\r\n");
}

void left_move_90angle(void)
{
    IoTGpioSetOutputVal(DIR_GPIO, 1);//4
    for (int i = 0; i < 44; i++) 
    {
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_HIGH);
        usleep(motorperiod); 
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_LOW);
        usleep(motorperiod);
    }
    printf("left_move_90angle finished!\r\n");
}

void left_move_120angle(void)
{
    IoTGpioSetOutputVal(DIR_GPIO, 1);//5
    for (int i = 0; i < 62; i++) 
    {
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_HIGH);
        usleep(motorperiod); 
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_LOW);
        usleep(motorperiod);
    }
    printf("left_move_120angle finished!\r\n");
}

void left_move_150angle(void)
{
    IoTGpioSetOutputVal(DIR_GPIO, 1);//6
    for (int i = 0; i < 78; i++) 
    {
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_HIGH);
        usleep(motorperiod); 
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_LOW);
        usleep(motorperiod);
    }
    printf("left_move_150angle finished!\r\n");
}

void left_move_180angle(void)
{
    IoTGpioSetOutputVal(DIR_GPIO, 1);//7
    for (int i = 0; i < 90; i++)
    {
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_HIGH);
        usleep(motorperiod); 
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_LOW);
        usleep(motorperiod);
    }
    printf("left_move_180angle finished!\r\n");
}

void right_move_30angle(void)
{
    IoTGpioSetOutputVal(DIR_GPIO, 0);
    for (int i = 0; i < 15; i++) 
    {
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_HIGH);
        usleep(motorperiod); 
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_LOW);
        usleep(motorperiod);
    }
    printf("right_move_30angle finished!\r\n");
}

void right_move_60angle(void)
{
    IoTGpioSetOutputVal(DIR_GPIO, 0);
    for (int i = 0; i < 28; i++) 
    {
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_HIGH);
        usleep(motorperiod); 
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_LOW);
        usleep(motorperiod);
    }
    printf("right_move_60angle finished!\r\n");
}

void right_move_90angle(void)
{
    IoTGpioSetOutputVal(DIR_GPIO, 0);
    for (int i = 0; i < 44; i++) 
    {
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_HIGH);
        usleep(motorperiod); 
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_LOW);
        usleep(motorperiod);
    }
    printf("right_move_90angle finished!\r\n");
}

void right_move_120angle(void)
{
    IoTGpioSetOutputVal(DIR_GPIO, 0);
    for (int i = 0; i < 62; i++) 
    {
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_HIGH);
        usleep(motorperiod); 
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_LOW);
        usleep(motorperiod);
    }
    printf("right_move_120angle finished!\r\n");
}

void right_move_150angle(void)
{
    IoTGpioSetOutputVal(DIR_GPIO, 0);
    for (int i = 0; i < 78; i++) 
    {
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_HIGH);
        usleep(motorperiod); 
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_LOW);
        usleep(motorperiod);
    }
    printf("right_move_150angle finished!\r\n");
}

void right_move_180angle(void)
{
    IoTGpioSetOutputVal(DIR_GPIO, 0);
    for (int i = 0; i < 90; i++)
    {
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_HIGH);
        usleep(motorperiod); 
        IoTGpioSetOutputVal(STEEP_GPIO, GPIO_LOW);
        usleep(motorperiod);
    }
    printf("right_move_180angle finished!\r\n");
}





void Motor_GpioInit(void)
{
    IoTGpioInit(STEEP_GPIO);
    IoTGpioInit(DIR_GPIO);
    IoTGpioSetDir(STEEP_GPIO, IOT_GPIO_DIR_OUT);
    IoTGpioSetDir(DIR_GPIO, IOT_GPIO_DIR_OUT);
}

