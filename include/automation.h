#include "global.h"
#include <iostream>
#include <stdlib.h>
#include <map>


using namespace std;

struct { int relay; int sensors; int value; } devices;
struct { int beginTime; int endTime; int function; } shedules;

// PRAGRAMMATION
struct Temp { int min; int max; };

extern Temp temp1, temp2, temp3, humidity1;

struct Program { 
    struct Summer {
        int begin;
        int end;
        struct Day {
            int begin;
            int end;
            Temp temp1;
            Temp temp2;
            Temp temp3;
            Temp humidity1;
        } day;
        struct Night {
            Temp temp1;
            Temp temp2;
            Temp temp3;
            Temp humidity1;
        } night;
    } summer;
    struct Winter {
        int begin;
        int end;
        struct Day {
            int begin;
            int end;
            Temp temp1;
            Temp temp2;
            Temp temp3;
            Temp humidity1;
        } day;
        struct Night {
            Temp temp1;
            Temp temp2;
            Temp temp3;
            Temp humidity1;
        } night;
    } winter;
};

extern Program program;


#define RELAY_INV 1

#if RELAY_INV == 0
    #define ON 0x1
    #define OFF 0x0
#else
    #define ON 0x0
    #define OFF 0x1
#endif

void automation(void);



