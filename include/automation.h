#include "global.h"
#include <iostream>
#include <stdlib.h>
#include <map>


using namespace std;

void automation(void);



struct { int relay; int sensors; int value; } devices;
struct { int beginTime; int endTime; int function; } shedules;
