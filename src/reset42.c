#include <stdio.h>
#include <stdlib.h>
#include "ohos_init.h"
#include "cmsis_os2.h"
#include "iot_watchdog.h"
#include "iot_gpio.h"
#include "hi_time.h"
#include "hi_io.h"
#include "iot_gpio.h"//iot_gpio.h
#include "reset42.h"

#define STEEP_GPIO 9
#define DIR_GPIO 11
#define TRIG_GPIO 0
#define ECHO_GPIO 5
//#define RESET_GPIO 12
#define MOTOR_TASK_STACK_SIZE 1024
#define GPIO_HIGH       (1)
#define GPIO_LOW        (0)

#define DELAY_US20    20
#define DELAY_MS10    10

void Motor_GpioInit1(void)
{
    IoTGpioInit(STEEP_GPIO);
    IoTGpioInit(DIR_GPIO);
    IoTGpioInit(ECHO_GPIO);
    IoTGpioInit(TRIG_GPIO);
    //IoTGpioInit(RESET_GPIO);
    IoTGpioSetDir(STEEP_GPIO, IOT_GPIO_DIR_OUT);
    IoTGpioSetDir(DIR_GPIO, IOT_GPIO_DIR_OUT);
    IoTGpioSetDir(ECHO_GPIO, IOT_GPIO_DIR_IN);
    IoTGpioSetDir(TRIG_GPIO, IOT_GPIO_DIR_OUT);
    //IoTGpioSetDir(RESET_GPIO, IOT_GPIO_DIR_IN);
}

float GetDistance(void)
{
    static unsigned long start_time = 0, time = 0;
    float distance = 0.0;
    IotGpioValue value = IOT_GPIO_VALUE0;
    unsigned int flag = 0;
    //trig发送信号
    IoTGpioSetOutputVal(TRIG_GPIO, IOT_GPIO_VALUE1);
    hi_udelay(DELAY_US20);
    IoTGpioSetOutputVal(TRIG_GPIO, IOT_GPIO_VALUE0);
    while (1) {
        //获取echo的状态
        IoTGpioGetInputVal(ECHO_GPIO, &value);
        //判断echo引脚的高低
        if (value == IOT_GPIO_VALUE1 && flag == 0) {
            //获取时间
            start_time = hi_get_us();
            flag = 1;
        }
        //判断GPIO8的输入电平是否为低电平并且flag为1
        if (value == IOT_GPIO_VALUE0 && flag == 1) {
            //获取高电平持续时间
            time = hi_get_us() - start_time;
            break;
        }
    }
    //计算距离障碍物距离（340米/秒 转换为 0.034厘米/微秒, 2代表去来，两倍距离） 
    distance = time * 0.034 / 2;//单位是cm
    return distance;
}

void ResetTask(void)
{
    Motor_GpioInit1();
    //IoTWatchDogDisable();
    IoTGpioSetOutputVal(DIR_GPIO, GPIO_LOW);//dir=0,向右转
    while (1) {
        float Distance = 0.0;
        // 调用函数并存储返回的距离值
        Distance = GetDistance();
        printf("Distance is %0.2f cm\r\n", Distance);
        if(Distance > 5.0){
            IoTGpioSetOutputVal(STEEP_GPIO, GPIO_LOW);
            usleep(20000); //0.1秒转1.8度
            IoTGpioSetOutputVal(STEEP_GPIO, GPIO_HIGH);
            usleep(20000);//0.1秒转1.8度
        }else{
            printf("复位完成/n/r");
            break;
        }
    }
}

// void reset_stop(void)
// {
//     while (1) {
//         IoTGpioSetOutputVal(STEEP_GPIO, GPIO_LOW);
//         IoTGpioSetOutputVal(DIR_GPIO, GPIO_LOW);
//     }
//     return NULL;
// }





/*
void ResetTask(void){
    Motor_GpioInit1();
    IoTWatchDogDisable();
    while(1){
        //IotGpioValue interrupt = IOT_GPIO_VALUE0;
        //IoTGpioGetInputVal(RESET_GPIO, &interrupt);
        float obstacleDistance = 0.0;
        // 调用函数并存储返回的距离值
        obstacleDistance = GetDistance();
        printf("distance is %0.2f cm\r\n", obstacleDistance);
        if(interrupt == 1){
            printf("开始复位");
            reset_begin();
            usleep(5000);
        }else{
            printf("无复位请求");
        }
        usleep(500000);
    }
}
*/
