#include "control.h"

int control_clamp(int input)
{
    if (input < 0)
        return 0;

    if (input > 100)
        return 100;

    return input;
}
