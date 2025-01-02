#include "global.h"
#include <iostream>
#include <stdlib.h>
#include <map>


using namespace std;


struct { int relay; int sensors; int value; } devices;
struct { int beginTime; int endTime; int function; } shedules;

#define RELAY_INV 1

#if RELAY_INV == 0
    #define ON 0x1
    #define OFF 0x0
#else
    #define ON 0x0
    #define OFF 0x1
#endif

void automation(void);



