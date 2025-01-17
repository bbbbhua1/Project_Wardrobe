#ifndef MOTOR42_H
#define MOTOR42_H

#include <stdint.h>

void left_move_30angle(void);
void left_move_60angle(void);
void left_move_90angle(void);
void left_move_120angle(void);
void left_move_150angle(void);
void left_move_180angle(void);
void right_move_30angle(void);
void right_move_60angle(void);
void right_move_90angle(void);
void right_move_120angle(void);
void right_move_150angle(void);
void right_move_180angle(void);
void Motor_GpioInit(void);

#endif  // MOTOR42_H

