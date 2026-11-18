#include "global.h"
namespace curve{
    class curvePeriod {
        public :
        static int season; // 0 = Summer, 1 = Winter

        void seasonCurve(void);
        int summerDays(void);
        int winterDays(void);
        void curveValues(void);
    };
}



