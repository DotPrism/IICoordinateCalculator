#include <cmath>
#define DEGREES_TO_RADIANS 0.017453292519943295;
#define RADIANS_TO_DEGREES 57.29577951308232;

#define MAX_FLOAT 0x1.fffffeP+127f;

class Math
{
public:
    static double toDegrees(double angrad) 
    {
        return angrad * RADIANS_TO_DEGREES;
    }

    static double toRadians(double angdeg) 
    {
        return angdeg * DEGREES_TO_RADIANS;
    }
};