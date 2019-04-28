#ifndef _APP_H_
#define _APP_H_

#define M0     4
#define DIR0   26

#define M1     3
#define DIR1   24

#define M2     2
#define DIR2   22

//#define M3     10
//#define DIR3   6

/*
T/C0: Pin6(OC0A)��Pin5(OC0B)

T/C1: Pin9(OC1A)��Pin10(OC1B)

T/C2: Pin11(OC2A)��Pin3(OC2B)
*/

void TaskRun(void);
void change_location(int X,int Y);
#endif
