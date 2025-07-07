#include <string>
#include "../globals.hpp"
#include "utils.hpp"

namespace DG2D
{
    namespace UTILS
    {
        bool ISdebug() //shit should work fine
        {
            #if(DEBUG == 1)
                DG2D::isdebugbuild = true;
                return true;
            #endif
            return false;
            DG2D::isdebugbuild = false;
        }
    }
}